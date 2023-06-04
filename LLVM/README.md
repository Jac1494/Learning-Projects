## LLVM reading links
- https://mukulrathi.com/create-your-own-programming-language/llvm-ir-cpp-api-tutorial/
- https://iq.opengenus.org/llvm-compiler-optimization/ (Multiple article related to LLVM)
- http://jonathan2251.github.io/lbd/about.html
- https://www.npopov.com/2022/12/20/This-year-in-LLVM-2022.html
- https://www.npopov.com/2021/06/02/Design-issues-in-LLVM-IR.html
- https://www.npopov.com/2020/05/10/Make-LLVM-fast-again.html
- https://sourcecodeartisan.com/2020/09/13/llvm-backend-0.html
- https://tomassetti.me/a-tutorial-on-how-to-write-a-compiler-using-llvm/

## LLVM Topics List
- [AST](#AST)
- [LLVMIR](#LLVMIR)
- [Opt tool](#Opt-tool) 
- [Optimization and Passes](#Optimization-and-Passes) 
- [PassConfig](#PassConfig)
- [Note](#Note)
- [Quick Flow of LLVM Source](#Quick-Flow-of-LLVM-Source) 

To write code syntax
```c++
generator<int> range(int start, int end) {
  while (start < end) {
    co_yield start;
    start++;
  }
```
To Highlight code use `range`.

## LLVM Topics details

### AST
- AST(Abstract syntax tree) is meaningful information may be stored in a data structure where the flow of code can be easily retrived.
- https://jonasdevlieghere.com/understanding-the-clang-ast/

### LLVMIR
**Why LLVM IR is important ..?**
- It is target independent , So we can write optimization and apply at IR level.
- It is SSA form, So each variable is assigned only once and every new assignment to a variable is new variable. Benefit of 
  this representation is that we don't have to do reaching definition analysis where some variable is assigned a value of another variable.
- SSA form also helps in no of optimization like const propogation , dead code elimination and others.
- Some of are important keyword/instruction of IR are as below
- LLVM use three address instruction. That is data processing instruction , which has two source operands and place the 
  result in a seperate destination operands.
  
  **1. getelementptr**
  - This instruction is used to get address of the element in an aggeregate data struture. It only calculate the address, don't access the memory.

  **2. insertelement**
  - Inserting a scalar into a vector

  **3. extractelement**
  - Extracting a scalar into a vector
 
 ```
   $ cat add.c
    #include<stdio.h>
    int Gvar = 11;
    int add_gvar(int x)
    {
            return Gvar + x;
    }
    int main()
    {
            printf("%d\n",add_gvar(22));
            return 0;
    }
 ```
 **$ clang add.c -S -emit-llvm -O0**
```
  $ cat add.ll
  ; ModuleID = 'add.c'  // LLVM define module for file name and LLVM module is top level data structure that conatins of the input LLVM file.
  source_filename = "add.c"
  target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
  // e => little endian
  // m : e => elf type
  // each specification seperate by "-"
  // i64:64  => 64 bit integer is of 64 bits

  target triple = "x86_64-pc-linux-gnu"  // This tells that target is x86_64 processor and running on LINUX machines.

  @Gvar = dso_local global i32 11, align 4  // Global variable/function access using `@` and local variable access using `%`.
  @.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

  ; Function Attrs: noinline nounwind optnone uwtable
  define dso_local i32 @add_gvar(i32 noundef %0) #0 {
    %2 = alloca i32, align 4
    store i32 %0, i32* %2, align 4
    %3 = load i32, i32* @Gvar, align 4
    %4 = load i32, i32* %2, align 4
    %5 = add nsw i32 %3, %4
    ret i32 %5
  }

  ; Function Attrs: noinline nounwind optnone uwtable
  define dso_local i32 @main() #0 {
    %1 = alloca i32, align 4
    store i32 0, i32* %1, align 4
    %2 = call i32 @add_gvar(i32 noundef 22)
    %3 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 noundef %2)
    ret i32 0
  }

  declare i32 @printf(i8* noundef, ...) #1
  // attributes given below used by optimization passes. Like we have copiled this code using "-O0". Because of that `optnone` attribute added below.
  // So if we try to apply other optimization level using opt tool like "-O1" or "-O2" then it will not work.
  attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
  attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

  !llvm.module.flags = !{!0, !1, !2, !3, !4}
  !llvm.ident = !{!5}

  !0 = !{i32 1, !"wchar_size", i32 4}
  !1 = !{i32 7, !"PIC Level", i32 2}
  !2 = !{i32 7, !"PIE Level", i32 2}
  !3 = !{i32 7, !"uwtable", i32 1}
  !4 = !{i32 7, !"frame-pointer", i32 2}
  !5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1"}
```
- LLVM IR have two types of local variables

  **1. Dynamic memory allocation in heap**
  ```
  $ cat test.cpp
  #include<stdio.h>
  int CreateVariable()
  {
          int *p=new int(99);
          return *p;
  }
  ...
  ...
  
  $ cat test.ll
  ...
  ...
  ; Function Attrs: mustprogress noinline optnone uwtable
  define dso_local noundef i32 @_Z14CreateVariablev() #0 {
    %1 = alloca i32*, align 8
    %2 = call noalias noundef nonnull i8* @_Znwm(i64 noundef 4) #3
    %3 = bitcast i8* %2 to i32*
    store i32 99, i32* %3, align 4
    store i32* %3, i32** %1, align 8
    %4 = load i32*, i32** %1, align 8
    %5 = load i32, i32* %4, align 4
    ret i32 %5
  }
  ...
  ...
  ```

  **2. Memory allocated for Local variable in Stack**

### Opt tool
- All llvm optimization list and details are avaialble at https://www.llvm.org/docs/Passes.html .
- To view which pass is being run at a certain optimization level. 
```
// For old pass manager
$ opt 2_math.ll -O2 -S -debug-pass=Structure -enable-new-pm=0

// For new pass manager (Looks efficient)
$ opt 2_math.ll -O2 -S -debug-pass-manager 

// Some of useful commands
$ opt -passes=dce -S 2_math.ll --print-before-all
$ opt -passes=dce -S 2_math.ll --print-after-all
```
- `We need to remove optnone from .ll(IR) file then only opt tool optimization will work`.

### Optimization and Passes
- The optimization pipelines are defined in https://github.com/llvm/llvm-project/blob/main/llvm/lib/Passes/PassBuilderPipelines.cpp . 
  And default pipeline is created by `buildPerModuleDefaultPipeline()` method.
- TODO:- Check this for both new and old pass manager

- **Types of passes**
  1. ModulePass              => **runOnModule**
  2. FunctionPass(Function   => **runOnFunction**
  3. BasicBlockPass          => **runOnBasicBloc**
  4. LoopPass(Loop           => **runOnLoop**
  5. **runOnRegion**(Region
  6. **runOnSCC**(CallGraphSCC

- **Passes class hierarcy**
  - **Pass Class**
    - **ModulePass**
      - **FunctionPass**
      - **doInitialization** => This is do initialization 
      - **runOn(Passtype)**  => This will implement our subclass for functionality
      - **doFinalization**   => This called after runOn(passtype) has finished doing the job.
      
- For each pass required analysis will be performed before executing pass (current pass required) by `getAnalysisUsage` method.
  ```
    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<AssumptionCacheTracker>();
      AU.addRequired<TargetTransformInfoWrapperPass>();
      AU.addPreserved<MemorySSAWrapperPass>();
      getLoopAnalysisUsage(AU);

      // Lazy BFI and BPI are marked as preserved here so LoopRotate
      // can remain part of the same loop pass manager as LICM.
      AU.addPreserved<LazyBlockFrequencyInfoPass>();
      AU.addPreserved<LazyBranchProbabilityInfoPass>();
    }
  ```
- AnalysisUsage.addRequired -> This method arrages for the execution of a Pass prior to the current Pass

- **Loop Passes**
  - All Loop related optimizations are derived from LoopPass class implemented in the LoopPass.CPP file locatted in lib/Analysis
    LPPassManager class is responsible for the handling of all LoopPasses.
  - Most important class for loop is LoopInfo class , it is used to identify the natural loops in code and to know the 
    depth of varies node of CFG.
  - In most of loop optimization , compiler used to perform Loop Simplication in that it will insert preheader to loop and one
    exit block also. So it will ensure that only single entry and exit point for loop , which helps to perform loop optimizations 
    like loop independent code motion.
  - Loop simiplify pass make sure that only one backedge will be there in that.
  - Alias Analysis is needed to move loop invariant loads and calls out of loop.

### PassConfig
- In LLVM everythings are implemented through pass . There are pass for optimization , backend , register allocation , scheduling etc..
- For each target seperate configuration are created , Also we can able set order of pass as per requirement.
- For each target seperate list of passes is there  `<TargetName>TargetMachine.cpp` as below
  ```
  ubuntu@LAPTOP-GS85CFD3:~/LLVM/llvm-project$ grep -irn createPassConfig | grep -v "^B" | grep -v "\.h" | grep Target
  llvm/tools/llvm-exegesis/lib/Assembler.cpp:228:  TargetPassConfig *TPC = TM->createPassConfig(PM);
  llvm/tools/llc/llc.cpp:705:      TargetPassConfig *PTPC = LLVMTM.createPassConfig(PM);
  llvm/lib/CodeGen/LLVMTargetMachine.cpp:110:  // Targets may override createPassConfig to provide a target-specific
  llvm/lib/CodeGen/LLVMTargetMachine.cpp:112:  TargetPassConfig *PassConfig = TM.createPassConfig(PM);
  llvm/lib/CodeGen/TargetPassConfig.cpp:646:/// createPassConfig - Create a pass configuration object to be used by
  llvm/lib/CodeGen/TargetPassConfig.cpp:650:TargetPassConfig *LLVMTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/BPF/BPFTargetMachine.cpp:101:TargetPassConfig *BPFTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/VE/VETargetMachine.cpp:131:TargetPassConfig *VETargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/SystemZ/SystemZTargetMachine.cpp:307:TargetPassConfig *SystemZTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/WebAssembly/WebAssemblyTargetMachine.cpp:358:WebAssemblyTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/Hexagon/HexagonTargetMachine.cpp:327:TargetPassConfig *HexagonTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/DirectX/DirectXTargetMachine.cpp:127:  TargetPassConfig *PassConfig = createPassConfig(PM);
  llvm/lib/Target/DirectX/DirectXTargetMachine.cpp:165:TargetPassConfig *DirectXTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/LoongArch/LoongArchTargetMachine.cpp:130:LoongArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/Mips/MipsTargetMachine.cpp:256:TargetPassConfig *MipsTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/SPIRV/SPIRVTargetMachine.cpp:140:TargetPassConfig *SPIRVTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/ARC/ARCTargetMachine.cpp:67:TargetPassConfig *ARCTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/ARM/ARMTargetMachine.cpp:408:TargetPassConfig *ARMBaseTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/M68k/M68kTargetMachine.cpp:166:TargetPassConfig *M68kTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/PowerPC/PPCTargetMachine.cpp:435:TargetPassConfig *PPCTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/XCore/XCoreTargetMachine.cpp:82:TargetPassConfig *XCoreTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/RISCV/RISCVTargetMachine.cpp:276:TargetPassConfig *RISCVTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/Lanai/LanaiTargetMachine.cpp:103:LanaiTargetMachine::createPassConfig(PassManagerBase &PassManager) {
  llvm/lib/Target/Sparc/SparcTargetMachine.cpp:172:TargetPassConfig *SparcTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/MSP430/MSP430TargetMachine.cpp:73:TargetPassConfig *MSP430TargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/Xtensa/XtensaTargetMachine.cpp:67:TargetPassConfig *XtensaTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/X86/X86TargetMachine.cpp:427:TargetPassConfig *X86TargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/AMDGPU/R600TargetMachine.cpp:144:TargetPassConfig *R600TargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/AMDGPU/AMDGPUTargetMachine.cpp:1405:TargetPassConfig *GCNTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/AArch64/AArch64TargetMachine.cpp:532:TargetPassConfig *AArch64TargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/AVR/AVRTargetMachine.cpp:78:TargetPassConfig *AVRTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/CSKY/CSKYTargetMachine.cpp:116:TargetPassConfig *CSKYTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/lib/Target/NVPTX/NVPTXTargetMachine.cpp:207:TargetPassConfig *NVPTXTargetMachine::createPassConfig(PassManagerBase &PM) {
  llvm/unittests/CodeGen/TargetOptionsTest.cpp:56:  TargetPassConfig *TPC = LLVMTM->createPassConfig(PM);
  ```
- To understand more in depth , we can use this as starting point and check methods as below
  ```
  ubuntu@LAPTOP-GS85CFD3:~/LLVM/llvm-project$ grep "bool X86PassConfig::" llvm/lib/Target/X86/X86TargetMachine.cpp
  bool X86PassConfig::addInstSelector() {
  bool X86PassConfig::addIRTranslator() {
  bool X86PassConfig::addLegalizeMachineIR() {
  bool X86PassConfig::addRegBankSelect() {
  bool X86PassConfig::addGlobalInstructionSelect() {
  bool X86PassConfig::addILPOpts() {
  bool X86PassConfig::addPreISel() {
  bool X86PassConfig::addPostFastRegAllocRewrite() {
  bool X86PassConfig::addRegAssignAndRewriteOptimized() {
  ```

### Note

- To check llvm code use ctags too. Installtion steps are
```
 sudo apt install exuberant-ctags
 sudo apt install universal-ctags
``` 
- Now cd to directory where source is there. I have run below command behind one directory in LLVM source.
```
ubuntu@LAPTOP-GS85CFD3:~/LLVM$ ls
llvm-project
ubuntu@LAPTOP-GS85CFD3:~/LLVM$ ctags -R *
ubuntu@LAPTOP-GS85CFD3:~/LLVM$ ls
llvm-project  tags
```
- Now open file and set curser to function then press "ctrl + ]" to go to function defination. And press "ctrl + o" to come back to call.

- In debugging to check TimeTraceScope to check module details. Currently which module it is like frontend , codegen, backend.etc
```
clang/lib/CodeGen/BackendUtil.cpp:1233:  llvm::TimeTraceScope TimeScope("Backend");
```

### Quick Flow of LLVM Source
**1. Frontend**

- All calls with source link

   - `clang_main` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/tools/driver/driver.cpp#L378
   - `ExecuteCC1Tool` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/tools/driver/driver.cpp#LL349C12-L349C26

   **// Actual compiler execution started by `cc1_main` which is do basic intialization for InitializeAllTargets, InitializeAllTargetMCs, InitializeAllAsmPrinters, InitializeAllAsmParsers**

   - `cc1_main` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/tools/driver/cc1_main.cpp#L185
   - `ExecuteCompilerInvocation` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/lib/FrontendTool/ExecuteCompilerInvocation.cpp#LL190C6-L190C31
   - `ExecuteAction` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/lib/Frontend/CompilerInstance.cpp#L1003	
   - `ASTFrontendAction::ExecuteAction` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/lib/Frontend/FrontendActions.cpp#L546

   - Clang codegen flow is started from below call. File https://github.com/llvm/llvm-project/blob/e76cfaca70be0b45e62149e52f68d8352fa8ea2f/clang/lib/CodeGen/ModuleBuilder.cpp#L364
      ```
      CodeGenerator *
      clang::CreateLLVMCodeGen(DiagnosticsEngine &Diags, llvm::StringRef ModuleName,
                               IntrusiveRefCntPtr<llvm::vfs::FileSystem> FS,
                               const HeaderSearchOptions &HeaderSearchOpts,
                               const PreprocessorOptions &PreprocessorOpts,
                               const CodeGenOptions &CGO, llvm::LLVMContext &C,
                               CoverageSourceInfo *CoverageInfo) {
        return new CodeGeneratorImpl(Diags, ModuleName, std::move(FS),
                                     HeaderSearchOpts, PreprocessorOpts, CGO, C,
                                     CoverageInfo);
      }
      ``` 
    - To debug clang codegen set breakpoints `CodeGeneratorImpl` , `Module`, `EmitTopLevelDecl`, `EmitGlobalFunctionDefinition` . 
    - Also to print current instruction or call use dump method
    ```
    (gdb) p D->dump()
    ...
    -BuiltinType 0x7fbc90 'unsigned short'
    $6 = void
    ```

   **// AST Parsing started by below method**
   - `ParseAST` https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/lib/Parse/ParseAST.cpp#L114
   
   **// LLVM IR generation start by below method**
   -  `HandleTranslationUnit` (Call) https://github.com/llvm/llvm-project/blob/87e6e490e79384a523bc7f0216c3db60227d6d58/clang/lib/Parse/ParseAST.cpp#L175
      (defination) https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/clang/lib/CodeGen/CodeGenAction.cpp#L299

   - To debug frontend in depth use the clang llvm pdf with all breakpoint details.

**2. Backend flow starting** 

  - `EmitBackendOutput` (Call) https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/clang/lib/CodeGen/CodeGenAction.cpp#L384
      (defination) https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/clang/lib/CodeGen/BackendUtil.cpp#L1224
  - `EmitAssemblyHelper::EmitAssembly` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/clang/lib/CodeGen/BackendUtil.cpp#L1095		

   **// All optimizations are invoked by** 
  -  `EmitAssemblyHelper::RunOptimizationPipeline`  https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/clang/lib/CodeGen/BackendUtil.cpp#L751

  -  `EmitAssemblyHelper::RunCodegenPipeline` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/clang/lib/CodeGen/BackendUtil.cpp#L1059
  -  It will further call `EmitAssemblyHelper::AddEmitPasses` in same method.

**3. LLVM Target specific flow started from below(Example X86)( source location shift to llvm folder )**

- `LLVMTargetMachine::addPassesToEmitFile` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/CodeGen/LLVMTargetMachine.cpp#L224 and in that method further it will invoked `addPassesToGenerateCode`. 
- `addPassesToGenerateCode` method invoked at https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/CodeGen/LLVMTargetMachine.cpp#L106. This method do instruction selection call which is done by  `addISelPasses` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/CodeGen/TargetPassConfig.cpp#L1087 , inside it will call `addCoreISelPasses` in same method. 
- `TargetPassConfig::addCoreISelPasses` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/CodeGen/TargetPassConfig.cpp#L1001 **this method will select FastIsel , GlobalIsel etc. **
- `TargetPassConfig::addCoreISelPasses` will further invoke `addInstSelector` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/CodeGen/TargetPassConfig.cpp#L1074 . **`addInstSelector` call target specific methods to perform legalization and other DAG related opearaton.**

 //  **X86 instruction selection // It is same for other architecture too(ARM etc-> r test.c -g -O0 --target=aarch64 -S)**
- Set brackpoint to all method available https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/Target/X86/X86TargetMachine.cpp#L389.
- https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/Target/X86/X86TargetMachine.cpp#L472
 
 ```
   bool X86PassConfig::addInstSelector() {
    // Install an instruction selector.
    addPass(createX86ISelDag(getX86TargetMachine(), getOptLevel()));

    // For ELF, cleanup any local-dynamic TLS accesses.
    if (TM->getTargetTriple().isOSBinFormatELF() &&
        getOptLevel() != CodeGenOpt::None)
      addPass(createCleanupLocalDynamicTLSPass());

    addPass(createX86GlobalBaseRegPass());
    addPass(createX86ArgumentStackSlotPass());
    return false;
  }
  ```
  
  - [https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/Target/X86/X86ISelDAGToDAG.cpp#LL6258C21-L6258C37](https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/Target/X86/X86ISelDAGToDAG.cpp#LL6258C21-L6258C37)
  
  ```
    ...
  /// This pass converts a legalized DAG into a X86-specific DAG,
  /// ready for instruction scheduling.
  FunctionPass *llvm::createX86ISelDag(X86TargetMachine &TM,
                                       CodeGenOpt::Level OptLevel) {
    return new X86DAGToDAGISel(TM, OptLevel);
  }
  ```
- Also `addPassesToGenerateCode` perform register allocation process `addFastRegAlloc`, `addMachineSSAOptimization`(Use 'O1' or Higher optimization level to invoke) , `addMachineLateOptimization`, Prolog/Epilog emition `createPrologEpilogInserterPass` by calling `addMachinePasses` https://github.com/llvm/llvm-project/blob/8a1373d3087b1103b402458a3118418d642bb3f5/llvm/lib/CodeGen/TargetPassConfig.cpp#L1128 . Also all backend level optimization performed by this method only.

