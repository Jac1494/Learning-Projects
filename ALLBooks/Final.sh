#!/bin/bash
#set -x

echo "Enter GCC version: 9.0(trunk) OR 8.1.0 OR 4.8.5"
read GCC_VERSION

echo "Enter Target name:"
read INPUT_ARCH 

export BINUTILS_VERSION="2.25.1"
export MPFR_VERSION="3.1.3"
export MPC_VERSION="1.0.3"
export GMP_VERSION="6.0.0a"
export GLIBC_VERSION="2.22"
export KERNEL_VERSION="4.1.10"

export CURR_DIR=`pwd`
export SRC=$CURR_DIR/
export PREFIX=$CURR_DIR/prefix
export BUILD=$CURR_DIR

echo "Downloading the Package"

set COUNT="0"

if [ $GCC_VERSION == "9.0" ] ; then
   COUNT=`find . -iname gcc-$GCC_VERSION |wc -l`
   if [ $COUNT == "0" ]; then
   svn checkout svn://gcc.gnu.org/svn/gcc/trunk gcc-$GCC_VERSION
   rm -rf .svn
   echo "GCC trunk"
   fi;
else
   COUNT=`find . -iname gcc-$GCC_VERSION.tar.gz |wc -l`
   if [ $COUNT == "0" ]; then
   wget https://ftp.gnu.org/gnu/gcc/gcc-$GCC_VERSION/gcc-$GCC_VERSION.tar.gz
   echo "GCC Downloaded"
   fi;
fi;

COUNT=`find . -iname mpfr-$MPFR_VERSION.tar.gz |wc -l`
if [ $COUNT == "0" ]; then
wget https://ftp.gnu.org/gnu/mpfr/mpfr-$MPFR_VERSION.tar.gz
echo "MPFR Downloaded"
fi;

COUNT=`find . -iname gmp-$GMP_VERSION.tar.xz |wc -l`
if [ $COUNT == "0" ]; then
wget https://ftp.gnu.org/gnu/gmp/gmp-$GMP_VERSION.tar.xz
echo "GMP Downloaded"
fi;

COUNT=`find . -iname gmp-$GMP_VERSION.tar.xz |wc -l`
if [ $COUNT == "0" ]; then
wget https://ftp.gnu.org/gnu/mpc/mpc-$MPC_VERSION.tar.gz
echo "MPC Downloaded"
fi;

COUNT=`find . -iname binutils-$BINUTILS_VERSION.tar.gz |wc -l`
if [ $COUNT == "0" ]; then
wget https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.gz
echo "BINUTILS Downloaded"
fi;

COUNT=`find . -iname linux-$KERNEL_VERSION.tar.xz |wc -l`
if [ $COUNT == "0" ]; then
wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-$KERNEL_VERSION.tar.xz
echo "Linux kernel Downloaded"
fi;

COUNT=`find . -iname glibc-$GLIBC_VERSION.tar.gz |wc -l`
if [ $COUNT == "0" ]; then
wget https://ftp.gnu.org/gnu/glibc/glibc-$GLIBC_VERSION.tar.gz
echo "GLIBC Downloaded"
fi;

echo "completed downloading package"

echo "Extracting package"
for f in ./*.tar*; do tar xf $f; done
echo "ALL package extracted successfully"
cd gcc-$GCC_VERSION
patch -p1 < ../libatomic.patch
cd ..

if [ ! -d $BUILD/build-binutils ]; then
    mkdir $BUILD/build-binutils-$BINUTILS_VERSION;
fi;
if [ ! -d $BUILD/build-gcc ]; then
    mkdir $BUILD/build-gcc-$GCC_VERSION;
fi;
if [ ! -d $BUILD/build-glibc ]; then
    mkdir $BUILD/build-glibc-$GLIBC_VERSION;
fi;

cd $SRC/gcc-$GCC_VERSION
sed -i '/k prot/agcc_cv_libc_provides_ssp=yes' gcc/configure
unlink gmp
unlink mpfr
unlink mpc
if [ $GMP_VERSION == "6.0.0a" ]; then
	ln -s $BUILD/gmp-6.0.0 gmp
else
	ln -s $BUILD/gmp-$GMP_VERSION gmp
fi 
ln -s $BUILD/mpfr-$MPFR_VERSION mpfr
ln -s $BUILD/mpc-$MPC_VERSION mpc

echo "Target to Build"
#INPUT_ARCH=$1

case $INPUT_ARCH in
	arm|armeb)
           target=$INPUT_ARCH-windriver-linux-gnueabi
           program_prefix=$INPUT_ARCH-windriver-linux-gnueabi
            if [ $INPUT_ARCH == armeb ]; then
              target=$INPUT_ARCH-windriverv7atb-linux-gnueabi
	      program_prefix=$INPUT_ARCH-windriverv7atb-linux-gnueabi
	    fi
	   linux_arch=arm
	    ;;

	aarch64)
           # target=$INPUT_ARCH-windriver-linux
             target=$INPUT_ARCH-windriver-linux
             program_prefix=$INPUT_ARCH-windriver-linux
             linux_arch=arm64
            ;;

	powerpc|powerpc64|ppc|ppc64)
	   target=$INPUT_ARCH-windriver-linux
	   program_prefix=$INPUT_ARCH-windriver-linux
           linux_arch=powerpc
	   ;;
	mips|mips64)
           target=$INPUT_ARCH-windriver-linux
           program_prefix=$INPUT_ARCH-windriver-linux
	   linux_arch=mips
	   ;;
	x86_64)
           target=$INPUT_ARCH-windriver-linux
           program_prefix=$INPUT_ARCH-windriver-linux
	   linux_arch=x86
	   ;;
	x86)
           target=i586-windriver-linux
           program_prefix=i586-windriver-linux
	   linux_arch=x86
	   ;;
	i686)
          target=i686-windriver-linux
          program_prefix=i686-windriver-linux
          linux_arch=x86
	   ;;
	*)	
	   echo "Enter Valid arch{arm,arm64,powerpc,powerpc64,ppc,ppc64,mips,mips64,x86_64,x86,i586} to build."
	   exit 1
	;;
esac	  



cd $BUILD/build-binutils-$BINUTILS_VERSION
#1. Configuration used for Binutils 
echo "Binutils configure Running"
if ! $SRC/binutils-$BINUTILS_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --disable-silent-rules --disable-dependency-tracking --program-prefix=$program_prefix-  --disable-werror --enable-plugins --enable-gold --disable-multilib --enable-ld=default > configure.out 2>&1; then
echo "Binutils configure failed"
exit 1
fi;
echo "Binutils make Running"
if ! make -j40 > make.out 2>&1; then
echo "Binutils make failed"
exit 1
fi;
echo "Binutils make install Running"
if ! make -j40 install > makeinstall.out 2>&1; then
echo "Binutils make install failed"
exit 1
fi;

cd $SRC/linux-$KERNEL_VERSION
echo "Make in Linux Running"
if ! make -j40 ARCH=$linux_arch INSTALL_HDR_PATH=$PREFIX/$target headers_install > make.out 2>&1; then
echo "Make in Linux failed"
exit 1
fi;

export PATH=$PREFIX/bin:$PATH

#3. Configuration for GCC
cd $BUILD/build-gcc-$GCC_VERSION
echo "1st GCC configure Running"

case $INPUT_ARCH in
	powerpc|powerpc64|ppc|ppc64)
		if ! $SRC/gcc-$GCC_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --disable-silent-rules --disable-dependency-tracking --program-prefix=$program_prefix- --with-gnu-ld --enable-shared --enable-languages=c,c++ --enable-threads=posix --disable-multilib --enable-c99 --enable-long-long --enable-symvers=gnu --enable-libstdcxx-pch --without-local-prefix --enable-lto --enable-libssp --disable-bootstrap --disable-libmudflap --with-system-zlib --with-linker-hash-style=gnu --enable-linker-build-id --with-ppl=no --with-cloog=no --enable-checking=release --enable-cheaders=c_global --with-long-double-128 --enable-poison-system-directories --enable-target-optspace --enable-nls --enable-__cxa_atexit > configure.out 2>&1; then
#NOTE:-- CHANGE CFLAG FOR DEBUG MODE 
		echo "1st GCC configure powerpc failed"
		exit 1
		fi;
		;;

	mips64)
		if ! $SRC/gcc-$GCC_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --program-prefix=$program_prefix- --disable-silent-rules 		  --disable-dependency-tracking 		   --with-gnu-ld --enable-shared --enable-languages=c,c++ --enable-threads=posix --disable-multilib --enable-c99 --enable-long-long --enable-symvers=gnu --enable-libstdcxx-pch --without-local-prefix --enable-target-optspace --enable-lto --enable-libssp --disable-bootstrap --disable-libmudflap --with-system-zlib --with-linker-hash-style=sysv --enable-linker-build-id --with-ppl=no --with-cloog=no --enable-checking=release --enable-cheaders=c_global  --enable-poison-system-directories --enable-nls --enable-__cxa_atexit --with-abi=64 --with-arch-64=mips64 --with-tune-64=mips64  > configure.out 2>&1; then
		echo "1st GCC configure mips64 failed"
		exit 1
		fi;
;;

	mips|x86_64|x86|i686)
		if ! $SRC/gcc-$GCC_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --program-prefix=$program_prefix- --disable-silent-rules  --disable-dependency-tracking  --with-gnu-ld --enable-shared --enable-languages=c,c++ --enable-threads=posix --disable-multilib --enable-c99 --enable-long-long --enable-symvers=gnu --enable-libstdcxx-pch  --without-local-prefix --enable-target-optspace --enable-lto --enable-libssp --disable-bootstrap --disable-libmudflap --with-system-zlib --with-linker-hash-style=sysv --enable-linker-build-id --with-ppl=no --with-cloog=no --enable-checking=release  --enable-poison-system-directories  --enable-nls --enable-__cxa_atexit --disable-libmpx > configure.out 2>&1; then
		echo "1st GCC configure mips failed"
		exit 1
		fi;
		;;

	arm)
		if ! $SRC/gcc-$GCC_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --program-prefix=$program_prefix- --disable-silent-rules --disable-dependency-tracking --with-gnu-ld --enable-shared --enable-languages=c,c++ --enable-threads=posix --disable-multilib --enable-c99 --enable-long-long --enable-symvers=gnu --enable-libstdcxx-pch  --without-local-prefix --enable-target-optspace --enable-lto --enable-libssp --disable-bootstrap --disable-libmudflap --with-system-zlib --with-linker-hash-style=gnu --enable-linker-build-id --with-ppl=no --with-cloog=no --enable-checking=release --enable-cheaders=c_global   --enable-poison-system-directories  --enable-nls  > configure.out 2>&1; then
		echo "1st GCC configure arm failed"
		exit 1
		fi;
		;;

	aarch64)
		if ! $SRC/gcc-$GCC_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --program-prefix=$program_prefix- --exec_prefix=$PREFIX --disable-silent-rules --disable-dependency-tracking 		   --with-gnu-ld --enable-shared --enable-languages=c,c++ --enable-threads=posix --disable-multilib --enable-c99 --enable-long-long --enable-symvers=gnu --enable-libstdcxx-pch --without-local-prefix --enable-target-optspace --enable-lto --enable-libssp --disable-bootstrap --disable-libmudflap --with-system-zlib --with-linker-hash-style=gnu --enable-linker-build-id --with-ppl=no --with-cloog=no --enable-checking=release --enable-cheaders=c_global  --enable-poison-system-directories  --enable-nls --enable-__cxa_atexit  > configure.out 2>&1; then
		echo "1st GCC configure aarch64 failed"
		exit 1
		fi;
		;;

	armeb)
		if ! $SRC/gcc-$GCC_VERSION/configure --prefix=$PREFIX --build=x86_64-pc-linux --host=x86_64-pc-linux --target=$target --program-prefix=$program_prefix- --exec_prefix=$PREFIX --disable-silent-rules --disable-dependency-tracking  --with-gnu-ld --enable-shared --enable-languages=c,c++ --enable-threads=posix --disable-multilib --enable-c99 --enable-long-long --enable-symvers=gnu --enable-libstdcxx-pch --program-prefix=armeb-windriverv7atb-linux-gnueabi- --without-local-prefix --enable-target-optspace --enable-lto --enable-libssp --disable-bootstrap --disable-libmudflap --with-system-zlib --with-linker-hash-style=gnu --enable-linker-build-id --with-ppl=no --with-cloog=no --enable-checking=release --enable-cheaders=c_global --enable-poison-system-directories  --enable-nls --with-arch=armv7-a > configure.out 2>&1; then
		echo "1st GCC configure armeb failed"
		exit 1
		fi;
		;;


esac


echo "1st GCC make Running"
if ! make -j40 all-gcc > make1.out 2>&1; then
echo "1st GCC make failed"
exit 1
fi;
echo "1st GCC make install Running"
if ! make -j40 install-gcc > makeinstall1.out 2>&1; then
echo "1st GCC make install failed"
exit 1
fi;

#4. GLIBC Default Configuration
cd $BUILD/build-glibc-$GLIBC_VERSION
echo "1st GLIBC configure Running"
if ! $SRC/glibc-$GLIBC_VERSION/configure --prefix=$PREFIX/$target --build=$MACHTYPE --host=$target --target=$target --with-headers=$PREFIX/$target/include --disable-werror --disable-multilib libc_cv_forced_unwind=yes > configure.out 2>&1; then
echo "1st GLIBC configure failed"
exit 1
fi;
echo "Install Headers Running"
if ! make -j40 install-bootstrap-headers=yes install-headers > install-headers.out 2>&1; then
echo "Install Headers failed"
exit 1
fi;
echo "1st GLIBC make Running"
if ! make -j40 csu/subdir_lib > make1.out 2>&1; then
echo "1st GLIBC make failed"
exit 1
fi;
echo "1st GLIBC Install Running"
if ! install csu/crt1.o csu/crti.o csu/crtn.o $PREFIX/$target/lib > makeinstall1.out 2>&1; then
echo "1st GLIBC Install failed"
exit 1
fi;
echo "1st GLIBC Shared lib Install Running"
if ! $program_prefix-gcc -nostdlib -nostartfiles -shared -x c /dev/null -o $PREFIX/$target/lib/libc.so > sharedinstall.out 2>&1; then
echo "1st GLIBC Shared lib Install failed"
exit 1
fi;
echo "1st GLIBC stub check Running"
if ! touch $PREFIX/$target/include/gnu/stubs.h > stub.out 2>&1; then
echo "1st GLIBC stub check failed"
exit 1
fi;

#4.1 GLIBC Configuration for 64-bit


#5. AGAIN GCC
cd $BUILD/build-gcc-$GCC_VERSION
echo "2nd GCC make Running"
if ! make -j40 all-target-libgcc > make2.out 2>&1; then
echo "2nd GCC make failed"
exit 1
fi;
echo "2nd GCC make install Running"
if ! make -j40 install-target-libgcc > makeinstall2.out 2>&1; then
echo "2nd GCC make install failed"
exit 1
fi;

#6. AGAIN GLIBC
cd $BUILD/build-glibc-$GLIBC_VERSION
echo "2nd GLIBC make Running"
if ! make -j40 > make2.out 2>&1; then
echo "2nd GLIBC make failed"
exit 1
fi;
echo "2nd GLIBC make install Running"
if ! make -j40 install > makeinstall2.out 2>&1; then
echo "2nd GLIBC make install failed"
exit 1
fi;

#7. AGAIN GCC
cd $BUILD/build-gcc-$GCC_VERSION
echo "3rd GCC make Running"
if ! make -j40 > make3.out 2>&1; then
echo "3rd GCC make failed"
exit 1
fi;
echo "3rd GCC make install Running"
if ! make -j40 install > makeinstall3.out 2>&1; then
echo "3rd GCC make install failed as patch in libatomic/Makefile.* is not applied"
exit 1
fi;
