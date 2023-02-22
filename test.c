<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?fileVersion 4.0.0?><cproject storage_type_id="org.eclipse.cdt.core.XmlProjectDescriptionStorage">
	<storageModule moduleId="org.eclipse.cdt.core.settings">
		<cconfiguration id="com.crt.advproject.config.exe.debug.684508519">
			<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider" id="com.crt.advproject.config.exe.debug.684508519" moduleId="org.eclipse.cdt.core.settings" name="Debug">
				<externalSettings/>
				<extensions>
					<extension id="org.eclipse.cdt.core.ELF" point="org.eclipse.cdt.core.BinaryParser"/>
					<extension id="org.eclipse.cdt.core.GNU_ELF" point="org.eclipse.cdt.core.BinaryParser"/>
					<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GASErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GLDErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.CWDLocator" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GCCErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
				</extensions>
			</storageModule>
			<storageModule moduleId="cdtBuildSystem" version="4.0.0">
				<configuration artifactExtension="axf" artifactName="${ProjName}" buildArtefactType="org.eclipse.cdt.build.core.buildArtefactType.exe" buildProperties="org.eclipse.cdt.build.core.buildArtefactType=org.eclipse.cdt.build.core.buildArtefactType.exe" cleanCommand="rm -rf" description="Debug build" errorParsers="org.eclipse.cdt.core.CWDLocator;org.eclipse.cdt.core.GmakeErrorParser;org.eclipse.cdt.core.GCCErrorParser;org.eclipse.cdt.core.GLDErrorParser;org.eclipse.cdt.core.GASErrorParser" id="com.crt.advproject.config.exe.debug.684508519" name="Debug" parent="com.crt.advproject.config.exe.debug" postannouncebuildStep="Performing post-build steps" postbuildStep="arm-none-eabi-size &quot;${BuildArtifactFileName}&quot; ; arm-none-eabi-objcopy -O srec &quot;${BuildArtifactFileName}&quot; &quot;${BuildArtifactFileBaseName}.s19&quot; ; # arm-none-eabi-objcopy -v -O binary &quot;${BuildArtifactFileName}&quot; &quot;${BuildArtifactFileBaseName}.bin&quot; ; # checksum -p ${TargetChip} -d &quot;${BuildArtifactFileBaseName}.bin&quot;">
					<folderInfo id="com.crt.advproject.config.exe.debug.684508519." name="/" resourcePath="">
						<toolChain id="com.crt.advproject.toolchain.exe.debug.285166023" name="NXP MCU Tools" superClass="com.crt.advproject.toolchain.exe.debug">
							<targetPlatform binaryParser="org.eclipse.cdt.core.ELF;org.eclipse.cdt.core.GNU_ELF" id="com.crt.advproject.platform.exe.debug.153244415" name="ARM-based MCU (Debug)" superClass="com.crt.advproject.platform.exe.debug"/>
							<builder buildPath="${workspace_loc:/qr03_boot}/Debug" id="com.crt.advproject.builder.exe.debug.971741884" keepEnvironmentInBuildfile="false" managedBuildOn="true" name="Gnu Make Builder" superClass="com.crt.advproject.builder.exe.debug"/>
							<tool id="com.crt.advproject.cpp.exe.debug.828626310" name="MCU C++ Compiler" superClass="com.crt.advproject.cpp.exe.debug">
								<option id="com.crt.advproject.cpp.hdrlib.572008427" name="Library headers" superClass="com.crt.advproject.cpp.hdrlib" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.fpu.793951985" name="Floating point" superClass="com.crt.advproject.cpp.fpu" useByScannerDiscovery="true" value="com.crt.advproject.cpp.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.cpp.arch.2101460727" name="Architecture" superClass="com.crt.advproject.cpp.arch" useByScannerDiscovery="true" value="com.crt.advproject.cpp.target.cm7" valueType="enumerated"/>
								<option id="com.crt.advproject.cpp.misc.dialect.1499563" name="Language standard" superClass="com.crt.advproject.cpp.misc.dialect" useByScannerDiscovery="true"/>
								<option id="gnu.cpp.compiler.option.dialect.flags.885864646" name="Other dialect flags" superClass="gnu.cpp.compiler.option.dialect.flags" useByScannerDiscovery="true"/>
								<option id="gnu.cpp.compiler.option.preprocessor.nostdinc.1252870558" name="Do not search system directories (-nostdinc)" superClass="gnu.cpp.compiler.option.preprocessor.nostdinc" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.preprocessor.preprocess.419631380" name="Preprocess only (-E)" superClass="gnu.cpp.compiler.option.preprocessor.preprocess" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.preprocessor.def.356163557" name="Defined symbols (-D)" superClass="gnu.cpp.compiler.option.preprocessor.def" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.preprocessor.undef.603927428" name="Undefined symbols (-U)" superClass="gnu.cpp.compiler.option.preprocessor.undef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.include.paths.1301417519" name="Include paths (-I)" superClass="gnu.cpp.compiler.option.include.paths" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.include.files.773819891" name="Include files (-include)" superClass="gnu.cpp.compiler.option.include.files" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.exe.debug.option.optimization.level.278410401" name="Optimization Level" superClass="com.crt.advproject.cpp.exe.debug.option.optimization.level" useByScannerDiscovery="true"/>
								<option id="gnu.cpp.compiler.option.optimization.flags.1461216592" name="Other optimization flags" superClass="gnu.cpp.compiler.option.optimization.flags" useByScannerDiscovery="false" value="-fno-common" valueType="string"/>
								<option id="com.crt.advproject.cpp.exe.debug.option.debugging.level.1217476183" name="Debug Level" superClass="com.crt.advproject.cpp.exe.debug.option.debugging.level" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.other.1699635039" name="Other debugging flags" superClass="gnu.cpp.compiler.option.debugging.other" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.prof.196573098" name="Generate prof information (-p)" superClass="gnu.cpp.compiler.option.debugging.prof" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.gprof.761590791" name="Generate gprof information (-pg)" superClass="gnu.cpp.compiler.option.debugging.gprof" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.codecov.1343494928" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.cpp.compiler.option.debugging.codecov" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitaddress.733888114" name="Sanitize address (-fsanitize=address)" superClass="gnu.cpp.compiler.option.debugging.sanitaddress" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitpointers.696561388" name="Sanitize pointer operations (-fsanitize=pointer-compare -fsanitize=pointer-subtract)" superClass="gnu.cpp.compiler.option.debugging.sanitpointers" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitthread.515853083" name="Sanitize data race in multi-thread (-fsanitize=thread)" superClass="gnu.cpp.compiler.option.debugging.sanitthread" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitleak.1256371474" name="Sanitize memory leak (-fsanitize=leak)" superClass="gnu.cpp.compiler.option.debugging.sanitleak" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitundef.1008836637" name="Sanitize undefined behavior (-fsanitize=undefined)" superClass="gnu.cpp.compiler.option.debugging.sanitundef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.syntax.778545682" name="Check syntax only (-fsyntax-only)" superClass="gnu.cpp.compiler.option.warnings.syntax" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.pedantic.2108480144" name="Pedantic (-pedantic)" superClass="gnu.cpp.compiler.option.warnings.pedantic" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.pedantic.error.384719292" name="Pedantic warnings as errors (-pedantic-errors)" superClass="gnu.cpp.compiler.option.warnings.pedantic.error" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.nowarn.478783213" name="Inhibit all warnings (-w)" superClass="gnu.cpp.compiler.option.warnings.nowarn" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.allwarn.691958896" name="All warnings (-Wall)" superClass="gnu.cpp.compiler.option.warnings.allwarn" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.extrawarn.2009254533" name="Extra warnings (-Wextra)" superClass="gnu.cpp.compiler.option.warnings.extrawarn" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.toerrors.1466047086" name="Warnings as errors (-Werror)" superClass="gnu.cpp.compiler.option.warnings.toerrors" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wconversion.55298518" name="Implicit conversion warnings (-Wconversion)" superClass="gnu.cpp.compiler.option.warnings.wconversion" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wcastalign.1127661859" name="Pointer cast with different alignment (-Wcast-align)" superClass="gnu.cpp.compiler.option.warnings.wcastalign" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wcastqual.303628900" name="Removing type qualifier from cast target type (-Wcast-qual)" superClass="gnu.cpp.compiler.option.warnings.wcastqual" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wctordtorprivacy.1791962092" name="All ctor and dtor private (-Wctor-dtor-privacy)" superClass="gnu.cpp.compiler.option.warnings.wctordtorprivacy" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wdisabledopt.641029889" name="Requested optimization pass is disabled (-Wdisabled-optimization)" superClass="gnu.cpp.compiler.option.warnings.wdisabledopt" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wlogicalop.1903200905" name="Suspicious uses of logical operators (-Wlogical-op)" superClass="gnu.cpp.compiler.option.warnings.wlogicalop" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wmissingdecl.1414807579" name="Global function without previous declaration (-Wmissing-declarations)" superClass="gnu.cpp.compiler.option.warnings.wmissingdecl" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wmissingincdir.1834002286" name="User-supplied include directory does not exist (-Wmissing-include-dirs)" superClass="gnu.cpp.compiler.option.warnings.wmissingincdir" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wnoexccept.1080508855" name="Noexcept false but never throw exception (-Wnoexcept)" superClass="gnu.cpp.compiler.option.warnings.wnoexccept" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.woldstylecast.654445176" name="C-style cast used (-Wold-style-cast)" superClass="gnu.cpp.compiler.option.warnings.woldstylecast" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.woverloadedvirtual.2092634546" name="Function hides virtual functions from base class (-Woverloaded-virtual)" superClass="gnu.cpp.compiler.option.warnings.woverloadedvirtual" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wredundantdecl.650074353" name="More than one declaration in the same scope (-Wredundant-decls)" superClass="gnu.cpp.compiler.option.warnings.wredundantdecl" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wshadow.725702796" name="Local symbol shadows upper scope symbol (-Wshadow)" superClass="gnu.cpp.compiler.option.warnings.wshadow" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wsignconv.1542908117" name="Implicit conversions that may change the sign (-Wsign-conversion)" superClass="gnu.cpp.compiler.option.warnings.wsignconv" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wsignpromo.306586341" name="Overload resolution promotes unsigned to signed type (-Wsign-promo)" superClass="gnu.cpp.compiler.option.warnings.wsignpromo" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wstrictnullsent.929867736" name="Use of an uncasted NULL as sentinel (-Wstrict-null-sentinel)" superClass="gnu.cpp.compiler.option.warnings.wstrictnullsent" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wswitchdef.376097066" name="A switch statement does not have a default case (-Wswitch-default)" superClass="gnu.cpp.compiler.option.warnings.wswitchdef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wundef.509992718" name="An undefined identifier is evaluated in an #if directive (-Wundef)" superClass="gnu.cpp.compiler.option.warnings.wundef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.weffcpp.440926168" name="Effective C++ guidelines (-Weffc++)" superClass="gnu.cpp.compiler.option.warnings.weffcpp" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wfloatequal.1312653795" name="Direct float equal check (-Wfloat-equal)" superClass="gnu.cpp.compiler.option.warnings.wfloatequal" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.other.other.1040718545" name="Other flags" superClass="gnu.cpp.compiler.option.other.other" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.other.verbose.1535142941" name="Verbose (-v)" superClass="gnu.cpp.compiler.option.other.verbose" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.other.pic.619691370" name="Position Independent Code (-fPIC)" superClass="gnu.cpp.compiler.option.other.pic" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.misc.hardening.356796061" name="Hardening options (-fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow)" superClass="gnu.cpp.compiler.option.misc.hardening" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.misc.randomization.1078464309" name="Address randomization (-fPIE)" superClass="gnu.cpp.compiler.option.misc.randomization" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.lto.1004686041" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.cpp.lto" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.lto.fat.1889589123" name="Fat lto objects (-ffat-lto-objects)" superClass="com.crt.advproject.cpp.lto.fat" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.merge.constants.1697435264" name="Merge Identical Constants (-fmerge-constants)" superClass="com.crt.advproject.cpp.merge.constants" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.prefixmap.1870019585" name="Remove path from __FILE__ (-fmacro-prefix-map)" superClass="com.crt.advproject.cpp.prefixmap" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.thumb.1789459649" name="Thumb mode" superClass="com.crt.advproject.cpp.thumb" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.thumbinterwork.824111829" name="Enable Thumb interworking" superClass="com.crt.advproject.cpp.thumbinterwork" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.securestate.2009483839" name="TrustZone Project Type" superClass="com.crt.advproject.cpp.securestate" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.stackusage.969028356" name="Generate Stack Usage Info (-fstack-usage)" superClass="com.crt.advproject.cpp.stackusage" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.specs.1233788778" name="Specs" superClass="com.crt.advproject.cpp.specs" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.config.512831498" name="Obsolete (Config)" superClass="com.crt.advproject.cpp.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.store.694230035" name="Obsolete (Store)" superClass="com.crt.advproject.cpp.store" useByScannerDiscovery="false"/>
							</tool>
							<tool id="com.crt.advproject.gcc.exe.debug.893290723" name="MCU C Compiler" superClass="com.crt.advproject.gcc.exe.debug">
								<option id="com.crt.advproject.gcc.hdrlib.1596250787" name="Library headers" superClass="com.crt.advproject.gcc.hdrlib" useByScannerDiscovery="false" value="com.crt.advproject.gcc.hdrlib.newlib" valueType="enumerated"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.compiler.option.preprocessor.def.symbols.1860453450" name="Defined symbols (-D)" superClass="gnu.c.compiler.option.preprocessor.def.symbols" useByScannerDiscovery="false" valueType="definedSymbols">
									<listOptionValue builtIn="false" value="CPU_MIMXRT1176AVM8A"/>
									<listOptionValue builtIn="false" value="CPU_MIMXRT1176AVM8A_cm4"/>
									<listOptionValue builtIn="false" value="CPU_MIMXRT1176DVMAA_cm7"/>
									<listOptionValue builtIn="false" value="XIP_BOOT_HEADER_DCD_ENABLE=1"/>
									<listOptionValue builtIn="false" value="USE_SDRAM"/>
									<listOptionValue builtIn="false" value="DATA_SECTION_IS_CACHEABLE=1"/>
									<listOptionValue builtIn="false" value="SDK_DEBUGCONSOLE=1"/>
									<listOptionValue builtIn="false" value="XIP_EXTERNAL_FLASH=1"/>
									<listOptionValue builtIn="false" value="XIP_BOOT_HEADER_ENABLE=1"/>
									<listOptionValue builtIn="false" value="PRINTF_FLOAT_ENABLE=0"/>
									<listOptionValue builtIn="false" value="SCANF_FLOAT_ENABLE=0"/>
									<listOptionValue builtIn="false" value="PRINTF_ADVANCED_ENABLE=0"/>
									<listOptionValue builtIn="false" value="SCANF_ADVANCED_ENABLE=0"/>
									<listOptionValue builtIn="false" value="FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1"/>
									<listOptionValue builtIn="false" value="MCUXPRESSO_SDK"/>
									<listOptionValue builtIn="false" value="CR_INTEGER_PRINTF"/>
									<listOptionValue builtIn="false" value="__MCUXPRESSO"/>
									<listOptionValue builtIn="false" value="__USE_CMSIS"/>
									<listOptionValue builtIn="false" value="DEBUG"/>
									<listOptionValue builtIn="false" value="__NEWLIB__"/>
								</option>
								<option id="com.crt.advproject.gcc.fpu.210681582" name="Floating point" superClass="com.crt.advproject.gcc.fpu" useByScannerDiscovery="true" value="com.crt.advproject.gcc.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.gcc.thumb.1691778322" name="Thumb mode" superClass="com.crt.advproject.gcc.thumb" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.gcc.arch.1497562695" name="Architecture" superClass="com.crt.advproject.gcc.arch" useByScannerDiscovery="true" value="com.crt.advproject.gcc.target.cm7" valueType="enumerated"/>
								<option id="com.crt.advproject.c.misc.dialect.1743773713" name="Language standard" superClass="com.crt.advproject.c.misc.dialect" useByScannerDiscovery="true" value="com.crt.advproject.misc.dialect.gnu99" valueType="enumerated"/>
								<option id="gnu.c.compiler.option.dialect.flags.1897256598" name="Other dialect flags" superClass="gnu.c.compiler.option.dialect.flags" useByScannerDiscovery="true"/>
								<option id="gnu.c.compiler.option.preprocessor.nostdinc.221644074" name="Do not search system directories (-nostdinc)" superClass="gnu.c.compiler.option.preprocessor.nostdinc" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.preprocessor.preprocess.1890167834" name="Preprocess only (-E)" superClass="gnu.c.compiler.option.preprocessor.preprocess" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.preprocessor.undef.symbol.357406225" name="Undefined symbols (-U)" superClass="gnu.c.compiler.option.preprocessor.undef.symbol" useByScannerDiscovery="false"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.compiler.option.include.paths.2014311229" name="Include paths (-I)" superClass="gnu.c.compiler.option.include.paths" useByScannerDiscovery="false" valueType="includePath">
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/board}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/customer/include}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/can}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/devices/TJA1043}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/flash}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/timer}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/can}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/can/can_aadl}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/can/uds}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/public}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/upgrade}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/utilities}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/drivers}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/device}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/component/uart}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/component/lists}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/startup}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/xip}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/CMSIS}&quot;"/>
								</option>
								<option id="gnu.c.compiler.option.include.files.1807373178" name="Include files (-include)" superClass="gnu.c.compiler.option.include.files" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.exe.debug.option.optimization.level.292722074" name="Optimization Level" superClass="com.crt.advproject.gcc.exe.debug.option.optimization.level" useByScannerDiscovery="true"/>
								<option id="gnu.c.compiler.option.optimization.flags.234546020" name="Other optimization flags" superClass="gnu.c.compiler.option.optimization.flags" useByScannerDiscovery="false" value="-fno-common" valueType="string"/>
								<option id="com.crt.advproject.gcc.exe.debug.option.debugging.level.1843989204" name="Debug Level" superClass="com.crt.advproject.gcc.exe.debug.option.debugging.level" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.other.438382657" name="Other debugging flags" superClass="gnu.c.compiler.option.debugging.other" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.prof.1867804766" name="Generate prof information (-p)" superClass="gnu.c.compiler.option.debugging.prof" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.gprof.984853895" name="Generate gprof information (-pg)" superClass="gnu.c.compiler.option.debugging.gprof" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.codecov.447111441" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.c.compiler.option.debugging.codecov" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitaddress.2094771708" name="Sanitize address (-fsanitize=address)" superClass="gnu.c.compiler.option.debugging.sanitaddress" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitpointers.364879955" name="Sanitize pointer operations (-fsanitize=pointer-compare -fsanitize=pointer-subtract)" superClass="gnu.c.compiler.option.debugging.sanitpointers" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitthread.152533953" name="Sanitize data race in multi-thread (-fsanitize=thread)" superClass="gnu.c.compiler.option.debugging.sanitthread" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitleak.383570911" name="Sanitize memory leak (-fsanitize=leak)" superClass="gnu.c.compiler.option.debugging.sanitleak" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitundef.1743091085" name="Sanitize undefined behavior (-fsanitize=undefined)" superClass="gnu.c.compiler.option.debugging.sanitundef" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.syntax.1801492643" name="Check syntax only (-fsyntax-only)" superClass="gnu.c.compiler.option.warnings.syntax" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.pedantic.873320358" name="Pedantic (-pedantic)" superClass="gnu.c.compiler.option.warnings.pedantic" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.pedantic.error.139918281" name="Pedantic warnings as errors (-pedantic-errors)" superClass="gnu.c.compiler.option.warnings.pedantic.error" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.nowarn.1467455320" name="Inhibit all warnings (-w)" superClass="gnu.c.compiler.option.warnings.nowarn" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.allwarn.858572557" name="All warnings (-Wall)" superClass="gnu.c.compiler.option.warnings.allwarn" useByScannerDiscovery="false" value="false" valueType="boolean"/>
								<option id="gnu.c.compiler.option.warnings.extrawarn.1648658556" name="Extra warnings (-Wextra)" superClass="gnu.c.compiler.option.warnings.extrawarn" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.toerrors.2007577340" name="Warnings as errors (-Werror)" superClass="gnu.c.compiler.option.warnings.toerrors" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wconversion.559793231" name="Implicit conversion warnings (-Wconversion)" superClass="gnu.c.compiler.option.warnings.wconversion" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wcastalign.1962406174" name="Pointer cast with different alignment (-Wcast-align)" superClass="gnu.c.compiler.option.warnings.wcastalign" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wcastqual.878847300" name="Removing type qualifier from cast target type (-Wcast-qual)" superClass="gnu.c.compiler.option.warnings.wcastqual" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wdisabledopt.1900291013" name="Requested optimization pass is disabled (-Wdisabled-optimization)" superClass="gnu.c.compiler.option.warnings.wdisabledopt" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wlogicalop.1920124597" name="Suspicious uses of logical operators (-Wlogical-op)" superClass="gnu.c.compiler.option.warnings.wlogicalop" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wmissingdecl.441344543" name="Global function without previous declaration (-Wmissing-declarations)" superClass="gnu.c.compiler.option.warnings.wmissingdecl" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wmissingincdir.909442404" name="User-supplied include directory does not exist (-Wmissing-include-dirs)" superClass="gnu.c.compiler.option.warnings.wmissingincdir" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wredundantdecl.382106289" name="More than one declaration in the same scope (-Wredundant-decls)" superClass="gnu.c.compiler.option.warnings.wredundantdecl" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wshadow.1455803632" name="Local symbol shadows upper scope symbol (-Wshadow)" superClass="gnu.c.compiler.option.warnings.wshadow" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wsignconv.475822866" name="Implicit conversions that may change the sign (-Wsign-conversion)" superClass="gnu.c.compiler.option.warnings.wsignconv" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wswitchdef.531680377" name="A switch statement does not have a default case (-Wswitch-default)" superClass="gnu.c.compiler.option.warnings.wswitchdef" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wundef.365025459" name="An undefined identifier is evaluated in an #if directive (-Wundef)" superClass="gnu.c.compiler.option.warnings.wundef" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wwritestrings.233657108" name="Treat strings always as const (-Wwrite-strings)" superClass="gnu.c.compiler.option.warnings.wwritestrings" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wfloatequal.440850209" name="Direct float equal check (-Wfloat-equal)" superClass="gnu.c.compiler.option.warnings.wfloatequal" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.other.358573011" name="Other flags" superClass="gnu.c.compiler.option.misc.other" useByScannerDiscovery="false" value="-c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin" valueType="string"/>
								<option id="gnu.c.compiler.option.misc.verbose.1825851407" name="Verbose (-v)" superClass="gnu.c.compiler.option.misc.verbose" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.ansi.39730006" name="Support ANSI programs (-ansi)" superClass="gnu.c.compiler.option.misc.ansi" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.pic.1094522777" name="Position Independent Code (-fPIC)" superClass="gnu.c.compiler.option.misc.pic" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.hardening.134103820" name="Hardening options (-fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow)" superClass="gnu.c.compiler.option.misc.hardening" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.randomization.1867197111" name="Address randomization (-fPIE)" superClass="gnu.c.compiler.option.misc.randomization" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.lto.1495668460" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.gcc.lto" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.lto.fat.1998529334" name="Fat lto objects (-ffat-lto-objects)" superClass="com.crt.advproject.gcc.lto.fat" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.merge.constants.1957000487" name="Merge Identical Constants (-fmerge-constants)" superClass="com.crt.advproject.gcc.merge.constants" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.prefixmap.2083061725" name="Remove path from __FILE__ (-fmacro-prefix-map)" superClass="com.crt.advproject.gcc.prefixmap" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.thumbinterwork.708160676" name="Enable Thumb interworking" superClass="com.crt.advproject.gcc.thumbinterwork" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.securestate.404269966" name="TrustZone Project Type" superClass="com.crt.advproject.gcc.securestate" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.stackusage.349060502" name="Generate Stack Usage Info (-fstack-usage)" superClass="com.crt.advproject.gcc.stackusage" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.specs.189361865" name="Specs" superClass="com.crt.advproject.gcc.specs" useByScannerDiscovery="false" value="com.crt.advproject.gcc.specs.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gcc.config.2020518917" name="Obsolete (Config)" superClass="com.crt.advproject.gcc.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.store.435536014" name="Obsolete (Store)" superClass="com.crt.advproject.gcc.store" useByScannerDiscovery="false"/>
								<inputType id="com.crt.advproject.compiler.input.416572107" superClass="com.crt.advproject.compiler.input"/>
							</tool>
							<tool id="com.crt.advproject.gas.exe.debug.1844254180" name="MCU Assembler" superClass="com.crt.advproject.gas.exe.debug">
								<option id="com.crt.advproject.gas.hdrlib.895112670" name="Library headers" superClass="com.crt.advproject.gas.hdrlib" useByScannerDiscovery="false" value="com.crt.advproject.gas.hdrlib.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gas.fpu.969149229" name="Floating point" superClass="com.crt.advproject.gas.fpu" useByScannerDiscovery="false" value="com.crt.advproject.gas.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.gas.thumb.2114836215" name="Thumb mode" superClass="com.crt.advproject.gas.thumb" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.gas.arch.284204734" name="Architecture" superClass="com.crt.advproject.gas.arch" useByScannerDiscovery="false" value="com.crt.advproject.gas.target.cm7" valueType="enumerated"/>
								<option id="gnu.both.asm.option.flags.crt.1429908203" name="Assembler flags" superClass="gnu.both.asm.option.flags.crt" useByScannerDiscovery="false" value="-c -x assembler-with-cpp -D__NEWLIB__" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.both.asm.option.include.paths.143847418" name="Include paths (-I)" superClass="gnu.both.asm.option.include.paths" useByScannerDiscovery="false" valueType="includePath">
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/board}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source}&quot;"/>
								</option>
								<option id="gnu.both.asm.option.warnings.nowarn.8217441" name="Suppress warnings (-W)" superClass="gnu.both.asm.option.warnings.nowarn" useByScannerDiscovery="false"/>
								<option id="gnu.both.asm.option.version.1413066786" name="Announce version (-v)" superClass="gnu.both.asm.option.version" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.exe.debug.option.debugging.level.1539275469" name="Debug level" superClass="com.crt.advproject.gas.exe.debug.option.debugging.level" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.thumbinterwork.873921456" name="Enable Thumb interworking" superClass="com.crt.advproject.gas.thumbinterwork" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.specs.320125923" name="Specs" superClass="com.crt.advproject.gas.specs" useByScannerDiscovery="false" value="com.crt.advproject.gas.specs.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gas.config.1349934330" name="Obsolete (Config)" superClass="com.crt.advproject.gas.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.store.546914656" name="Obsolete (Store)" superClass="com.crt.advproject.gas.store" useByScannerDiscovery="false"/>
								<inputType id="cdt.managedbuild.tool.gnu.assembler.input.1116504431" superClass="cdt.managedbuild.tool.gnu.assembler.input"/>
								<inputType id="com.crt.advproject.assembler.input.145601640" name="Additional Assembly Source Files" superClass="com.crt.advproject.assembler.input"/>
							</tool>
							<tool id="com.crt.advproject.link.cpp.exe.debug.120132567" name="MCU C++ Linker" superClass="com.crt.advproject.link.cpp.exe.debug">
								<option id="com.crt.advproject.link.cpp.hdrlib.706776823" name="Library" superClass="com.crt.advproject.link.cpp.hdrlib"/>
								<option id="com.crt.advproject.link.cpp.fpu.178962605" name="Floating point" superClass="com.crt.advproject.link.cpp.fpu" value="com.crt.advproject.link.cpp.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.link.cpp.arch.1463665838" name="Architecture" superClass="com.crt.advproject.link.cpp.arch" value="com.crt.advproject.link.cpp.target.cm7" valueType="enumerated"/>
								<option id="com.crt.advproject.link.cpp.multicore.slave.2072500872" name="Multicore configuration" superClass="com.crt.advproject.link.cpp.multicore.slave"/>
								<option id="gnu.cpp.link.option.nostart.1865584617" name="Do not use standard start files (-nostartfiles)" superClass="gnu.cpp.link.option.nostart"/>
								<option id="gnu.cpp.link.option.nodeflibs.968953595" name="Do not use default libraries (-nodefaultlibs)" superClass="gnu.cpp.link.option.nodeflibs"/>
								<option id="gnu.cpp.link.option.nostdlibs.1314588162" name="No startup or default libs (-nostdlib)" superClass="gnu.cpp.link.option.nostdlibs" value="true" valueType="boolean"/>
								<option id="gnu.cpp.link.option.strip.1379383551" name="Omit all symbol information (-s)" superClass="gnu.cpp.link.option.strip"/>
								<option id="gnu.cpp.link.option.libs.263428981" name="Libraries (-l)" superClass="gnu.cpp.link.option.libs"/>
								<option id="gnu.cpp.link.option.paths.1937749283" name="Library search path (-L)" superClass="gnu.cpp.link.option.paths"/>
								<option id="gnu.cpp.link.option.flags.39405717" name="Linker flags" superClass="gnu.cpp.link.option.flags"/>
								<option id="gnu.cpp.link.option.other.710356358" name="Other options (-Xlinker [option])" superClass="gnu.cpp.link.option.other"/>
								<option id="gnu.cpp.link.option.userobjs.1920023015" name="Other objects" superClass="gnu.cpp.link.option.userobjs"/>
								<option id="gnu.cpp.link.option.shared.572344095" name="Shared (-shared)" superClass="gnu.cpp.link.option.shared"/>
								<option id="gnu.cpp.link.option.soname.1970580785" name="Shared object name (-Wl,-soname=)" superClass="gnu.cpp.link.option.soname"/>
								<option id="gnu.cpp.link.option.implname.1414760588" name="Import Library name (-Wl,--out-implib=)" superClass="gnu.cpp.link.option.implname"/>
								<option id="gnu.cpp.link.option.defname.304915592" name="DEF file name (-Wl,--output-def=)" superClass="gnu.cpp.link.option.defname"/>
								<option id="gnu.cpp.link.option.debugging.prof.691963872" name="Generate prof information (-p)" superClass="gnu.cpp.link.option.debugging.prof"/>
								<option id="gnu.cpp.link.option.debugging.gprof.57906400" name="Generate gprof information (-pg)" superClass="gnu.cpp.link.option.debugging.gprof"/>
								<option id="gnu.cpp.link.option.debugging.codecov.1355802367" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.cpp.link.option.debugging.codecov"/>
								<option id="com.crt.advproject.link.cpp.lto.1822282773" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.link.cpp.lto"/>
								<option id="com.crt.advproject.link.cpp.lto.optmization.level.155128797" name="Link-time optimization level" superClass="com.crt.advproject.link.cpp.lto.optmization.level"/>
								<option id="com.crt.advproject.link.cpp.thumb.133760292" name="Thumb mode" superClass="com.crt.advproject.link.cpp.thumb"/>
								<option id="com.crt.advproject.link.cpp.manage.1872697986" name="Manage linker script" superClass="com.crt.advproject.link.cpp.manage"/>
								<option id="com.crt.advproject.link.cpp.script.1346498762" name="Linker script" superClass="com.crt.advproject.link.cpp.script"/>
								<option id="com.crt.advproject.link.cpp.scriptdir.1678842504" name="Script path" superClass="com.crt.advproject.link.cpp.scriptdir"/>
								<option id="com.crt.advproject.link.cpp.crpenable.1180658256" name="Enable automatic placement of Code Read Protection field in image" superClass="com.crt.advproject.link.cpp.crpenable"/>
								<option id="com.crt.advproject.link.cpp.flashconfigenable.1120894813" name="Enable automatic placement of Flash Configuration field in image" superClass="com.crt.advproject.link.cpp.flashconfigenable" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.cpp.ecrp.1339905214" name="Enhanced CRP" superClass="com.crt.advproject.link.cpp.ecrp"/>
								<option id="com.crt.advproject.link.cpp.nanofloat.687530307" name="Enable printf float " superClass="com.crt.advproject.link.cpp.nanofloat"/>
								<option id="com.crt.advproject.link.cpp.nanofloat.scanf.451072234" name="Enable scanf float " superClass="com.crt.advproject.link.cpp.nanofloat.scanf"/>
								<option id="com.crt.advproject.link.cpp.toram.1731127988" name="Link application to RAM" superClass="com.crt.advproject.link.cpp.toram"/>
								<option id="com.crt.advproject.link.memory.load.image.cpp.1181182943" name="Plain load image" superClass="com.crt.advproject.link.memory.load.image.cpp"/>
								<option id="com.crt.advproject.link.memory.heapAndStack.style.cpp.1624180010" name="Heap and Stack placement" superClass="com.crt.advproject.link.memory.heapAndStack.style.cpp"/>
								<option id="com.crt.advproject.link.cpp.stackOffset.1165061669" name="Stack offset" superClass="com.crt.advproject.link.cpp.stackOffset"/>
								<option id="com.crt.advproject.link.memory.heapAndStack.cpp.1668374876" name="Heap and Stack options" superClass="com.crt.advproject.link.memory.heapAndStack.cpp"/>
								<option id="com.crt.advproject.link.memory.data.cpp.1018322641" name="Global data placement" superClass="com.crt.advproject.link.memory.data.cpp"/>
								<option id="com.crt.advproject.link.memory.sections.cpp.2089028247" name="Extra linker script input sections" superClass="com.crt.advproject.link.memory.sections.cpp"/>
								<option id="com.crt.advproject.link.cpp.multicore.master.1373039443" name="Multicore master" superClass="com.crt.advproject.link.cpp.multicore.master"/>
								<option id="com.crt.advproject.link.cpp.multicore.empty.651616394" name="No Multicore options for this project" superClass="com.crt.advproject.link.cpp.multicore.empty"/>
								<option id="com.crt.advproject.link.cpp.multicore.master.userobjs.712016711" name="Slave Objects (not visible)" superClass="com.crt.advproject.link.cpp.multicore.master.userobjs"/>
								<option id="com.crt.advproject.link.cpp.config.1436734304" name="Obsolete (Config)" superClass="com.crt.advproject.link.cpp.config"/>
								<option id="com.crt.advproject.link.cpp.store.716609427" name="Obsolete (Store)" superClass="com.crt.advproject.link.cpp.store"/>
								<option id="com.crt.advproject.link.cpp.securestate.1211750200" name="TrustZone Project Type" superClass="com.crt.advproject.link.cpp.securestate"/>
								<option id="com.crt.advproject.link.cpp.sgstubs.placement.2047063783" name="Secure Gateway Placement" superClass="com.crt.advproject.link.cpp.sgstubs.placement"/>
								<option id="com.crt.advproject.link.cpp.sgstubenable.1454235420" name="Enable generation of Secure Gateway Import Library" superClass="com.crt.advproject.link.cpp.sgstubenable"/>
								<option id="com.crt.advproject.link.cpp.nonsecureobject.1062663782" name="Secure Gateway Import Library" superClass="com.crt.advproject.link.cpp.nonsecureobject"/>
								<option id="com.crt.advproject.link.cpp.inimplib.2047957608" name="Input Secure Gateway Import Library" superClass="com.crt.advproject.link.cpp.inimplib"/>
							</tool>
							<tool id="com.crt.advproject.link.exe.debug.1171537014" name="MCU Linker" superClass="com.crt.advproject.link.exe.debug">
								<option id="com.crt.advproject.link.gcc.hdrlib.1554734037" name="Library" superClass="com.crt.advproject.link.gcc.hdrlib" useByScannerDiscovery="false" value="com.crt.advproject.gcc.link.hdrlib.newlib.nohost" valueType="enumerated"/>
								<option id="com.crt.advproject.link.fpu.686913722" name="Floating point" superClass="com.crt.advproject.link.fpu" useByScannerDiscovery="false" value="com.crt.advproject.link.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.link.thumb.176879414" name="Thumb mode" superClass="com.crt.advproject.link.thumb" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.memory.load.image.237220244" name="Plain load image" superClass="com.crt.advproject.link.memory.load.image" useByScannerDiscovery="false" value="false;" valueType="string"/>
								<option defaultValue="com.crt.advproject.heapAndStack.mcuXpressoStyle" id="com.crt.advproject.link.memory.heapAndStack.style.1119988807" name="Heap and Stack placement" superClass="com.crt.advproject.link.memory.heapAndStack.style" useByScannerDiscovery="false" valueType="enumerated"/>
								<option id="com.crt.advproject.link.memory.heapAndStack.1681812089" name="Heap and Stack options" superClass="com.crt.advproject.link.memory.heapAndStack" useByScannerDiscovery="false" value="&amp;Heap:Default;Post Data;Default&amp;Stack:Default;End;Default" valueType="string"/>
								<option id="com.crt.advproject.link.memory.data.456329438" name="Global data placement" superClass="com.crt.advproject.link.memory.data" useByScannerDiscovery="false" value="Default" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.crt.advproject.link.memory.sections.1837551548" name="Extra linker script input sections" superClass="com.crt.advproject.link.memory.sections" useByScannerDiscovery="false" valueType="stringList">
									<listOptionValue builtIn="false" value="isd=KEEP(*(CodeQuickAccess));region=SRAM_ITC_cm7;type=.data"/>
									<listOptionValue builtIn="false" value="isd=*(NonCacheable.init);region=NCACHE_REGION;type=.data"/>
									<listOptionValue builtIn="false" value="isd=*(NonCacheable);region=NCACHE_REGION;type=.bss"/>
								</option>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="true" id="com.crt.advproject.link.gcc.multicore.master.userobjs.1655988653" name="Slave Objects (not visible)" superClass="com.crt.advproject.link.gcc.multicore.master.userobjs" useByScannerDiscovery="false" valueType="userObjs"/>
								<option id="com.crt.advproject.link.gcc.multicore.slave.985995660" name="Multicore configuration" superClass="com.crt.advproject.link.gcc.multicore.slave" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.arch.208605081" name="Architecture" superClass="com.crt.advproject.link.arch" useByScannerDiscovery="false" value="com.crt.advproject.link.target.cm7" valueType="enumerated"/>
								<option id="gnu.c.link.option.nostart.641042891" name="Do not use standard start files (-nostartfiles)" superClass="gnu.c.link.option.nostart" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.nodeflibs.1459035722" name="Do not use default libraries (-nodefaultlibs)" superClass="gnu.c.link.option.nodeflibs" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.nostdlibs.1341243664" name="No startup or default libs (-nostdlib)" superClass="gnu.c.link.option.nostdlibs" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="gnu.c.link.option.strip.688468102" name="Omit all symbol information (-s)" superClass="gnu.c.link.option.strip" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.noshared.1835441223" name="No shared libraries (-static)" superClass="gnu.c.link.option.noshared" useByScannerDiscovery="false"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.link.option.libs.270096532" name="Libraries (-l)" superClass="gnu.c.link.option.libs" useByScannerDiscovery="false" valueType="libs">
									<listOptionValue builtIn="false" value=":lib_security_access.a"/>
								</option>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.link.option.paths.1366906813" name="Library search path (-L)" superClass="gnu.c.link.option.paths" useByScannerDiscovery="false" valueType="libPaths">
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/customer/lib}&quot;"/>
								</option>
								<option id="gnu.c.link.option.ldflags.845580537" name="Linker flags" superClass="gnu.c.link.option.ldflags" useByScannerDiscovery="false"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.link.option.other.1251283218" name="Other options (-Xlinker [option])" superClass="gnu.c.link.option.other" useByScannerDiscovery="false" valueType="stringList">
									<listOptionValue builtIn="false" value="-Map=&quot;${BuildArtifactFileBaseName}.map&quot;"/>
									<listOptionValue builtIn="false" value="--gc-sections"/>
									<listOptionValue builtIn="false" value="-print-memory-usage"/>
									<listOptionValue builtIn="false" value="--sort-section=alignment"/>
									<listOptionValue builtIn="false" value="--cref"/>
								</option>
								<option id="gnu.c.link.option.userobjs.499638304" name="Other objects" superClass="gnu.c.link.option.userobjs" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.shared.2075240067" name="Shared (-shared)" superClass="gnu.c.link.option.shared" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.soname.580546613" name="Shared object name (-Wl,-soname=)" superClass="gnu.c.link.option.soname" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.implname.1536305972" name="Import Library name (-Wl,--out-implib=)" superClass="gnu.c.link.option.implname" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.defname.807262503" name="DEF file name (-Wl,--output-def=)" superClass="gnu.c.link.option.defname" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.debugging.prof.1068088231" name="Generate prof information (-p)" superClass="gnu.c.link.option.debugging.prof" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.debugging.gprof.331153620" name="Generate gprof information (-pg)" superClass="gnu.c.link.option.debugging.gprof" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.debugging.codecov.445923233" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.c.link.option.debugging.codecov" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.lto.1404671542" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.link.gcc.lto" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.lto.optmization.level.993169955" name="Link-time optimization level" superClass="com.crt.advproject.link.gcc.lto.optmization.level" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.manage.366982975" name="Manage linker script" superClass="com.crt.advproject.link.manage" useByScannerDiscovery="false" value="false" valueType="boolean"/>
								<option id="com.crt.advproject.link.script.1814029258" name="Linker script" superClass="com.crt.advproject.link.script" useByScannerDiscovery="false" value="qr03_boot_Debug.ld" valueType="string"/>
								<option id="com.crt.advproject.link.scriptdir.493884947" name="Script path" superClass="com.crt.advproject.link.scriptdir" useByScannerDiscovery="false" value="&quot;${workspace_loc:/${ProjName}/linker}&quot;" valueType="string"/>
								<option id="com.crt.advproject.link.crpenable.874840542" name="Enable automatic placement of Code Read Protection field in image" superClass="com.crt.advproject.link.crpenable" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.flashconfigenable.1304163842" name="Enable automatic placement of Flash Configuration field in image" superClass="com.crt.advproject.link.flashconfigenable" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.ecrp.1044992887" name="Enhanced CRP" superClass="com.crt.advproject.link.ecrp" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.nanofloat.1668819071" name="Enable printf float " superClass="com.crt.advproject.link.gcc.nanofloat" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.nanofloat.scanf.1329503823" name="Enable scanf float " superClass="com.crt.advproject.link.gcc.nanofloat.scanf" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.toram.885596345" name="Link application to RAM" superClass="com.crt.advproject.link.toram" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.stackOffset.685573143" name="Stack offset" superClass="com.crt.advproject.link.stackOffset" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.multicore.master.1064339014" name="Multicore master" superClass="com.crt.advproject.link.gcc.multicore.master" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.multicore.empty.1249892042" name="No Multicore options for this project" superClass="com.crt.advproject.link.gcc.multicore.empty" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.config.1108766291" name="Obsolete (Config)" superClass="com.crt.advproject.link.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.store.1414806580" name="Obsolete (Store)" superClass="com.crt.advproject.link.store" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.securestate.1589101061" name="TrustZone Project Type" superClass="com.crt.advproject.link.securestate" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.sgstubs.placement.1460697071" name="Secure Gateway Placement" superClass="com.crt.advproject.link.sgstubs.placement" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.sgstubenable.449554917" name="Enable generation of Secure Gateway Import Library" superClass="com.crt.advproject.link.sgstubenable" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.nonsecureobject.390744057" name="Secure Gateway Import Library" superClass="com.crt.advproject.link.nonsecureobject" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.inimplib.226467396" name="Input Secure Gateway Import Library" superClass="com.crt.advproject.link.inimplib" useByScannerDiscovery="false"/>
								<inputType id="cdt.managedbuild.tool.gnu.c.linker.input.1698852377" superClass="cdt.managedbuild.tool.gnu.c.linker.input">
									<additionalInput kind="additionalinputdependency" paths="$(USER_OBJS)"/>
									<additionalInput kind="additionalinput" paths="$(LIBS)"/>
								</inputType>
							</tool>
							<tool id="com.crt.advproject.tool.debug.debug.1942645635" name="MCU Debugger" superClass="com.crt.advproject.tool.debug.debug">
								<option id="com.crt.advproject.linkserver.debug.prevent.debug.743056155" name="Prevent Debugging" superClass="com.crt.advproject.linkserver.debug.prevent.debug" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.miscellaneous.end_of_heap.1471490200" name="Last used address of the heap" superClass="com.crt.advproject.miscellaneous.end_of_heap" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.miscellaneous.pvHeapStart.1466566922" name="First address of the heap" superClass="com.crt.advproject.miscellaneous.pvHeapStart" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.miscellaneous.pvHeapLimit.1079946590" name="Maximum extent of heap" superClass="com.crt.advproject.miscellaneous.pvHeapLimit" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.debugger.security.nonsecureimageenable.107634361" name="Enable pre-programming of Non-Secure Image" superClass="com.crt.advproject.debugger.security.nonsecureimageenable" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.debugger.security.nonsecureimage.1516172389" name="Non-Secure Project" superClass="com.crt.advproject.debugger.security.nonsecureimage" useByScannerDiscovery="false"/>
							</tool>
						</toolChain>
					</folderInfo>
					<sourceEntries>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="component"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="startup"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="CMSIS"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="source"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="utilities"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="drivers"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="device"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="board"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="xip"/>
					</sourceEntries>
				</configuration>
			</storageModule>
			<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
		</cconfiguration>
		<cconfiguration id="com.crt.advproject.config.exe.release.1974876544">
			<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider" id="com.crt.advproject.config.exe.release.1974876544" moduleId="org.eclipse.cdt.core.settings" name="Release">
				<externalSettings/>
				<extensions>
					<extension id="org.eclipse.cdt.core.ELF" point="org.eclipse.cdt.core.BinaryParser"/>
					<extension id="org.eclipse.cdt.core.GNU_ELF" point="org.eclipse.cdt.core.BinaryParser"/>
					<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GASErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GLDErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.CWDLocator" point="org.eclipse.cdt.core.ErrorParser"/>
					<extension id="org.eclipse.cdt.core.GCCErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
				</extensions>
			</storageModule>
			<storageModule moduleId="cdtBuildSystem" version="4.0.0">
				<configuration artifactExtension="axf" artifactName="${ProjName}" buildArtefactType="org.eclipse.cdt.build.core.buildArtefactType.exe" buildProperties="org.eclipse.cdt.build.core.buildArtefactType=org.eclipse.cdt.build.core.buildArtefactType.exe" cleanCommand="rm -rf" description="Release build" errorParsers="org.eclipse.cdt.core.CWDLocator;org.eclipse.cdt.core.GmakeErrorParser;org.eclipse.cdt.core.GCCErrorParser;org.eclipse.cdt.core.GLDErrorParser;org.eclipse.cdt.core.GASErrorParser" id="com.crt.advproject.config.exe.release.1974876544" name="Release" parent="com.crt.advproject.config.exe.release" postannouncebuildStep="Performing post-build steps" postbuildStep="arm-none-eabi-size &quot;${BuildArtifactFileName}&quot; ; arm-none-eabi-objcopy -O srec &quot;${BuildArtifactFileName}&quot; &quot;${BuildArtifactFileBaseName}.s19&quot; ; # arm-none-eabi-objcopy -v -O binary &quot;${BuildArtifactFileName}&quot; &quot;${BuildArtifactFileBaseName}.bin&quot; ; # checksum -p ${TargetChip} -d &quot;${BuildArtifactFileBaseName}.bin&quot;">
					<folderInfo id="com.crt.advproject.config.exe.release.1974876544." name="/" resourcePath="">
						<toolChain id="com.crt.advproject.toolchain.exe.release.1755497650" name="NXP MCU Tools" superClass="com.crt.advproject.toolchain.exe.release">
							<targetPlatform binaryParser="org.eclipse.cdt.core.ELF;org.eclipse.cdt.core.GNU_ELF" id="com.crt.advproject.platform.exe.release.851210625" name="ARM-based MCU (Release)" superClass="com.crt.advproject.platform.exe.release"/>
							<builder buildPath="${workspace_loc:/qr03_boot}/Release" id="com.crt.advproject.builder.exe.release.1162411581" keepEnvironmentInBuildfile="false" managedBuildOn="true" name="Gnu Make Builder" superClass="com.crt.advproject.builder.exe.release"/>
							<tool id="com.crt.advproject.cpp.exe.release.1375038901" name="MCU C++ Compiler" superClass="com.crt.advproject.cpp.exe.release">
								<option id="com.crt.advproject.cpp.arch.910515759" name="Architecture" superClass="com.crt.advproject.cpp.arch" useByScannerDiscovery="true" value="com.crt.advproject.cpp.target.cm7" valueType="enumerated"/>
								<option id="com.crt.advproject.cpp.misc.dialect.1124011233" name="Language standard" superClass="com.crt.advproject.cpp.misc.dialect" useByScannerDiscovery="true"/>
								<option id="gnu.cpp.compiler.option.dialect.flags.721099269" name="Other dialect flags" superClass="gnu.cpp.compiler.option.dialect.flags" useByScannerDiscovery="true"/>
								<option id="gnu.cpp.compiler.option.preprocessor.nostdinc.714359971" name="Do not search system directories (-nostdinc)" superClass="gnu.cpp.compiler.option.preprocessor.nostdinc" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.preprocessor.preprocess.1680129725" name="Preprocess only (-E)" superClass="gnu.cpp.compiler.option.preprocessor.preprocess" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.preprocessor.def.1457932525" name="Defined symbols (-D)" superClass="gnu.cpp.compiler.option.preprocessor.def" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.preprocessor.undef.1456611282" name="Undefined symbols (-U)" superClass="gnu.cpp.compiler.option.preprocessor.undef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.include.paths.316359908" name="Include paths (-I)" superClass="gnu.cpp.compiler.option.include.paths" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.include.files.999471078" name="Include files (-include)" superClass="gnu.cpp.compiler.option.include.files" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.optimization.flags.1158118016" name="Other optimization flags" superClass="gnu.cpp.compiler.option.optimization.flags" useByScannerDiscovery="false" value="-fno-common" valueType="string"/>
								<option id="gnu.cpp.compiler.option.debugging.other.690856702" name="Other debugging flags" superClass="gnu.cpp.compiler.option.debugging.other" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.prof.1770694826" name="Generate prof information (-p)" superClass="gnu.cpp.compiler.option.debugging.prof" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.gprof.2066522340" name="Generate gprof information (-pg)" superClass="gnu.cpp.compiler.option.debugging.gprof" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.codecov.879907093" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.cpp.compiler.option.debugging.codecov" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitaddress.46854592" name="Sanitize address (-fsanitize=address)" superClass="gnu.cpp.compiler.option.debugging.sanitaddress" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitpointers.29312985" name="Sanitize pointer operations (-fsanitize=pointer-compare -fsanitize=pointer-subtract)" superClass="gnu.cpp.compiler.option.debugging.sanitpointers" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitthread.1011345130" name="Sanitize data race in multi-thread (-fsanitize=thread)" superClass="gnu.cpp.compiler.option.debugging.sanitthread" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitleak.2041109980" name="Sanitize memory leak (-fsanitize=leak)" superClass="gnu.cpp.compiler.option.debugging.sanitleak" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.debugging.sanitundef.1153711515" name="Sanitize undefined behavior (-fsanitize=undefined)" superClass="gnu.cpp.compiler.option.debugging.sanitundef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.syntax.960855499" name="Check syntax only (-fsyntax-only)" superClass="gnu.cpp.compiler.option.warnings.syntax" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.pedantic.749316175" name="Pedantic (-pedantic)" superClass="gnu.cpp.compiler.option.warnings.pedantic" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.pedantic.error.1644047070" name="Pedantic warnings as errors (-pedantic-errors)" superClass="gnu.cpp.compiler.option.warnings.pedantic.error" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.nowarn.568266638" name="Inhibit all warnings (-w)" superClass="gnu.cpp.compiler.option.warnings.nowarn" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.allwarn.844806820" name="All warnings (-Wall)" superClass="gnu.cpp.compiler.option.warnings.allwarn" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.extrawarn.2082002138" name="Extra warnings (-Wextra)" superClass="gnu.cpp.compiler.option.warnings.extrawarn" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.toerrors.1593273745" name="Warnings as errors (-Werror)" superClass="gnu.cpp.compiler.option.warnings.toerrors" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wconversion.1004326174" name="Implicit conversion warnings (-Wconversion)" superClass="gnu.cpp.compiler.option.warnings.wconversion" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wcastalign.1234184325" name="Pointer cast with different alignment (-Wcast-align)" superClass="gnu.cpp.compiler.option.warnings.wcastalign" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wcastqual.1960803286" name="Removing type qualifier from cast target type (-Wcast-qual)" superClass="gnu.cpp.compiler.option.warnings.wcastqual" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wctordtorprivacy.1591216801" name="All ctor and dtor private (-Wctor-dtor-privacy)" superClass="gnu.cpp.compiler.option.warnings.wctordtorprivacy" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wdisabledopt.1899332352" name="Requested optimization pass is disabled (-Wdisabled-optimization)" superClass="gnu.cpp.compiler.option.warnings.wdisabledopt" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wlogicalop.1400280059" name="Suspicious uses of logical operators (-Wlogical-op)" superClass="gnu.cpp.compiler.option.warnings.wlogicalop" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wmissingdecl.1015391723" name="Global function without previous declaration (-Wmissing-declarations)" superClass="gnu.cpp.compiler.option.warnings.wmissingdecl" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wmissingincdir.1978928568" name="User-supplied include directory does not exist (-Wmissing-include-dirs)" superClass="gnu.cpp.compiler.option.warnings.wmissingincdir" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wnoexccept.83001080" name="Noexcept false but never throw exception (-Wnoexcept)" superClass="gnu.cpp.compiler.option.warnings.wnoexccept" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.woldstylecast.1317875395" name="C-style cast used (-Wold-style-cast)" superClass="gnu.cpp.compiler.option.warnings.woldstylecast" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.woverloadedvirtual.1929943567" name="Function hides virtual functions from base class (-Woverloaded-virtual)" superClass="gnu.cpp.compiler.option.warnings.woverloadedvirtual" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wredundantdecl.620268019" name="More than one declaration in the same scope (-Wredundant-decls)" superClass="gnu.cpp.compiler.option.warnings.wredundantdecl" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wshadow.1019010893" name="Local symbol shadows upper scope symbol (-Wshadow)" superClass="gnu.cpp.compiler.option.warnings.wshadow" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wsignconv.151589467" name="Implicit conversions that may change the sign (-Wsign-conversion)" superClass="gnu.cpp.compiler.option.warnings.wsignconv" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wsignpromo.2032034854" name="Overload resolution promotes unsigned to signed type (-Wsign-promo)" superClass="gnu.cpp.compiler.option.warnings.wsignpromo" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wstrictnullsent.1725888005" name="Use of an uncasted NULL as sentinel (-Wstrict-null-sentinel)" superClass="gnu.cpp.compiler.option.warnings.wstrictnullsent" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wswitchdef.925367162" name="A switch statement does not have a default case (-Wswitch-default)" superClass="gnu.cpp.compiler.option.warnings.wswitchdef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wundef.2140570437" name="An undefined identifier is evaluated in an #if directive (-Wundef)" superClass="gnu.cpp.compiler.option.warnings.wundef" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.weffcpp.2092515314" name="Effective C++ guidelines (-Weffc++)" superClass="gnu.cpp.compiler.option.warnings.weffcpp" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.warnings.wfloatequal.586327500" name="Direct float equal check (-Wfloat-equal)" superClass="gnu.cpp.compiler.option.warnings.wfloatequal" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.other.other.1441553525" name="Other flags" superClass="gnu.cpp.compiler.option.other.other" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.other.verbose.694963593" name="Verbose (-v)" superClass="gnu.cpp.compiler.option.other.verbose" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.other.pic.1943180486" name="Position Independent Code (-fPIC)" superClass="gnu.cpp.compiler.option.other.pic" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.misc.hardening.1027594942" name="Hardening options (-fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow)" superClass="gnu.cpp.compiler.option.misc.hardening" useByScannerDiscovery="false"/>
								<option id="gnu.cpp.compiler.option.misc.randomization.1097026630" name="Address randomization (-fPIE)" superClass="gnu.cpp.compiler.option.misc.randomization" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.lto.1187662678" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.cpp.lto" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.lto.fat.2068301602" name="Fat lto objects (-ffat-lto-objects)" superClass="com.crt.advproject.cpp.lto.fat" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.merge.constants.557094650" name="Merge Identical Constants (-fmerge-constants)" superClass="com.crt.advproject.cpp.merge.constants" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.prefixmap.1170314566" name="Remove path from __FILE__ (-fmacro-prefix-map)" superClass="com.crt.advproject.cpp.prefixmap" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.fpu.454664668" name="Floating point" superClass="com.crt.advproject.cpp.fpu" useByScannerDiscovery="true" value="com.crt.advproject.cpp.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.cpp.thumb.1661157077" name="Thumb mode" superClass="com.crt.advproject.cpp.thumb" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.thumbinterwork.1850986828" name="Enable Thumb interworking" superClass="com.crt.advproject.cpp.thumbinterwork" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.securestate.1625310599" name="TrustZone Project Type" superClass="com.crt.advproject.cpp.securestate" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.hdrlib.1190346725" name="Library headers" superClass="com.crt.advproject.cpp.hdrlib" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.stackusage.925549424" name="Generate Stack Usage Info (-fstack-usage)" superClass="com.crt.advproject.cpp.stackusage" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.specs.1033570082" name="Specs" superClass="com.crt.advproject.cpp.specs" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.config.1394101542" name="Obsolete (Config)" superClass="com.crt.advproject.cpp.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.cpp.store.375438522" name="Obsolete (Store)" superClass="com.crt.advproject.cpp.store" useByScannerDiscovery="false"/>
							</tool>
							<tool id="com.crt.advproject.gcc.exe.release.621598700" name="MCU C Compiler" superClass="com.crt.advproject.gcc.exe.release">
								<option id="com.crt.advproject.gcc.thumb.1437557270" name="Thumb mode" superClass="com.crt.advproject.gcc.thumb" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.gcc.arch.726037295" name="Architecture" superClass="com.crt.advproject.gcc.arch" useByScannerDiscovery="true" value="com.crt.advproject.gcc.target.cm7" valueType="enumerated"/>
								<option id="com.crt.advproject.c.misc.dialect.822325557" name="Language standard" superClass="com.crt.advproject.c.misc.dialect" useByScannerDiscovery="true" value="com.crt.advproject.misc.dialect.gnu99" valueType="enumerated"/>
								<option id="gnu.c.compiler.option.dialect.flags.229110896" name="Other dialect flags" superClass="gnu.c.compiler.option.dialect.flags" useByScannerDiscovery="true"/>
								<option id="gnu.c.compiler.option.preprocessor.nostdinc.467375102" name="Do not search system directories (-nostdinc)" superClass="gnu.c.compiler.option.preprocessor.nostdinc" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.preprocessor.preprocess.638977958" name="Preprocess only (-E)" superClass="gnu.c.compiler.option.preprocessor.preprocess" useByScannerDiscovery="false"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.compiler.option.preprocessor.def.symbols.396409842" name="Defined symbols (-D)" superClass="gnu.c.compiler.option.preprocessor.def.symbols" useByScannerDiscovery="false" valueType="definedSymbols">
									<listOptionValue builtIn="false" value="CPU_MIMXRT1176AVM8A"/>
									<listOptionValue builtIn="false" value="CPU_MIMXRT1176AVM8A_cm4"/>
									<listOptionValue builtIn="false" value="CPU_MIMXRT1176DVMAA_cm7"/>
									<listOptionValue builtIn="false" value="XIP_BOOT_HEADER_DCD_ENABLE=1"/>
									<listOptionValue builtIn="false" value="USE_SDRAM"/>
									<listOptionValue builtIn="false" value="DATA_SECTION_IS_CACHEABLE=1"/>
									<listOptionValue builtIn="false" value="SDK_DEBUGCONSOLE=1"/>
									<listOptionValue builtIn="false" value="XIP_EXTERNAL_FLASH=1"/>
									<listOptionValue builtIn="false" value="XIP_BOOT_HEADER_ENABLE=1"/>
									<listOptionValue builtIn="false" value="PRINTF_FLOAT_ENABLE=0"/>
									<listOptionValue builtIn="false" value="SCANF_FLOAT_ENABLE=0"/>
									<listOptionValue builtIn="false" value="PRINTF_ADVANCED_ENABLE=0"/>
									<listOptionValue builtIn="false" value="SCANF_ADVANCED_ENABLE=0"/>
									<listOptionValue builtIn="false" value="FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1"/>
									<listOptionValue builtIn="false" value="MCUXPRESSO_SDK"/>
									<listOptionValue builtIn="false" value="CR_INTEGER_PRINTF"/>
									<listOptionValue builtIn="false" value="__MCUXPRESSO"/>
									<listOptionValue builtIn="false" value="__USE_CMSIS"/>
									<listOptionValue builtIn="false" value="NDEBUG"/>
									<listOptionValue builtIn="false" value="__NEWLIB__"/>
								</option>
								<option id="gnu.c.compiler.option.preprocessor.undef.symbol.1128309781" name="Undefined symbols (-U)" superClass="gnu.c.compiler.option.preprocessor.undef.symbol" useByScannerDiscovery="false"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.compiler.option.include.paths.1215555038" name="Include paths (-I)" superClass="gnu.c.compiler.option.include.paths" useByScannerDiscovery="false" valueType="includePath">
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/board}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/can}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/devices/TJA1043}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/flash}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/ecual/timer}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/can}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/can/can_aadl}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/can/uds}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/public}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source/service/upgrade}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/utilities}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/drivers}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/device}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/component/uart}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/component/lists}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/startup}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/xip}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/CMSIS}&quot;"/>
								</option>
								<option id="gnu.c.compiler.option.include.files.383769687" name="Include files (-include)" superClass="gnu.c.compiler.option.include.files" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.optimization.flags.623627060" name="Other optimization flags" superClass="gnu.c.compiler.option.optimization.flags" useByScannerDiscovery="false" value="-fno-common" valueType="string"/>
								<option id="gnu.c.compiler.option.debugging.other.824155208" name="Other debugging flags" superClass="gnu.c.compiler.option.debugging.other" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.prof.676624610" name="Generate prof information (-p)" superClass="gnu.c.compiler.option.debugging.prof" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.gprof.446694947" name="Generate gprof information (-pg)" superClass="gnu.c.compiler.option.debugging.gprof" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.codecov.236161833" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.c.compiler.option.debugging.codecov" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitaddress.657383842" name="Sanitize address (-fsanitize=address)" superClass="gnu.c.compiler.option.debugging.sanitaddress" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitpointers.404177988" name="Sanitize pointer operations (-fsanitize=pointer-compare -fsanitize=pointer-subtract)" superClass="gnu.c.compiler.option.debugging.sanitpointers" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitthread.1887347112" name="Sanitize data race in multi-thread (-fsanitize=thread)" superClass="gnu.c.compiler.option.debugging.sanitthread" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitleak.1723815713" name="Sanitize memory leak (-fsanitize=leak)" superClass="gnu.c.compiler.option.debugging.sanitleak" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.debugging.sanitundef.19011959" name="Sanitize undefined behavior (-fsanitize=undefined)" superClass="gnu.c.compiler.option.debugging.sanitundef" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.syntax.1657311904" name="Check syntax only (-fsyntax-only)" superClass="gnu.c.compiler.option.warnings.syntax" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.pedantic.2069332299" name="Pedantic (-pedantic)" superClass="gnu.c.compiler.option.warnings.pedantic" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.pedantic.error.2054464749" name="Pedantic warnings as errors (-pedantic-errors)" superClass="gnu.c.compiler.option.warnings.pedantic.error" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.nowarn.1061769892" name="Inhibit all warnings (-w)" superClass="gnu.c.compiler.option.warnings.nowarn" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.allwarn.1948947165" name="All warnings (-Wall)" superClass="gnu.c.compiler.option.warnings.allwarn" useByScannerDiscovery="false" value="false" valueType="boolean"/>
								<option id="gnu.c.compiler.option.warnings.extrawarn.1694023370" name="Extra warnings (-Wextra)" superClass="gnu.c.compiler.option.warnings.extrawarn" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.toerrors.545440031" name="Warnings as errors (-Werror)" superClass="gnu.c.compiler.option.warnings.toerrors" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wconversion.127347773" name="Implicit conversion warnings (-Wconversion)" superClass="gnu.c.compiler.option.warnings.wconversion" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wcastalign.1117114737" name="Pointer cast with different alignment (-Wcast-align)" superClass="gnu.c.compiler.option.warnings.wcastalign" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wcastqual.1364960542" name="Removing type qualifier from cast target type (-Wcast-qual)" superClass="gnu.c.compiler.option.warnings.wcastqual" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wdisabledopt.1325087281" name="Requested optimization pass is disabled (-Wdisabled-optimization)" superClass="gnu.c.compiler.option.warnings.wdisabledopt" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wlogicalop.1637087671" name="Suspicious uses of logical operators (-Wlogical-op)" superClass="gnu.c.compiler.option.warnings.wlogicalop" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wmissingdecl.1189671134" name="Global function without previous declaration (-Wmissing-declarations)" superClass="gnu.c.compiler.option.warnings.wmissingdecl" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wmissingincdir.10196165" name="User-supplied include directory does not exist (-Wmissing-include-dirs)" superClass="gnu.c.compiler.option.warnings.wmissingincdir" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wredundantdecl.1012059514" name="More than one declaration in the same scope (-Wredundant-decls)" superClass="gnu.c.compiler.option.warnings.wredundantdecl" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wshadow.653073933" name="Local symbol shadows upper scope symbol (-Wshadow)" superClass="gnu.c.compiler.option.warnings.wshadow" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wsignconv.68389113" name="Implicit conversions that may change the sign (-Wsign-conversion)" superClass="gnu.c.compiler.option.warnings.wsignconv" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wswitchdef.690067037" name="A switch statement does not have a default case (-Wswitch-default)" superClass="gnu.c.compiler.option.warnings.wswitchdef" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wundef.1434128723" name="An undefined identifier is evaluated in an #if directive (-Wundef)" superClass="gnu.c.compiler.option.warnings.wundef" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wwritestrings.1104193812" name="Treat strings always as const (-Wwrite-strings)" superClass="gnu.c.compiler.option.warnings.wwritestrings" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.warnings.wfloatequal.295817413" name="Direct float equal check (-Wfloat-equal)" superClass="gnu.c.compiler.option.warnings.wfloatequal" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.other.336347433" name="Other flags" superClass="gnu.c.compiler.option.misc.other" useByScannerDiscovery="false" value="-c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin" valueType="string"/>
								<option id="gnu.c.compiler.option.misc.verbose.1860919511" name="Verbose (-v)" superClass="gnu.c.compiler.option.misc.verbose" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.ansi.171826990" name="Support ANSI programs (-ansi)" superClass="gnu.c.compiler.option.misc.ansi" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.pic.685972606" name="Position Independent Code (-fPIC)" superClass="gnu.c.compiler.option.misc.pic" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.hardening.567747891" name="Hardening options (-fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow)" superClass="gnu.c.compiler.option.misc.hardening" useByScannerDiscovery="false"/>
								<option id="gnu.c.compiler.option.misc.randomization.1561889889" name="Address randomization (-fPIE)" superClass="gnu.c.compiler.option.misc.randomization" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.lto.1170692092" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.gcc.lto" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.lto.fat.920016927" name="Fat lto objects (-ffat-lto-objects)" superClass="com.crt.advproject.gcc.lto.fat" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.merge.constants.1081327238" name="Merge Identical Constants (-fmerge-constants)" superClass="com.crt.advproject.gcc.merge.constants" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.prefixmap.432826693" name="Remove path from __FILE__ (-fmacro-prefix-map)" superClass="com.crt.advproject.gcc.prefixmap" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.fpu.547967422" name="Floating point" superClass="com.crt.advproject.gcc.fpu" useByScannerDiscovery="true" value="com.crt.advproject.gcc.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.gcc.thumbinterwork.1180440029" name="Enable Thumb interworking" superClass="com.crt.advproject.gcc.thumbinterwork" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.securestate.1181642444" name="TrustZone Project Type" superClass="com.crt.advproject.gcc.securestate" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.hdrlib.408183483" name="Library headers" superClass="com.crt.advproject.gcc.hdrlib" useByScannerDiscovery="false" value="com.crt.advproject.gcc.hdrlib.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gcc.stackusage.1018054079" name="Generate Stack Usage Info (-fstack-usage)" superClass="com.crt.advproject.gcc.stackusage" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.specs.404765756" name="Specs" superClass="com.crt.advproject.gcc.specs" useByScannerDiscovery="false" value="com.crt.advproject.gcc.specs.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gcc.config.865084813" name="Obsolete (Config)" superClass="com.crt.advproject.gcc.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gcc.store.25536416" name="Obsolete (Store)" superClass="com.crt.advproject.gcc.store" useByScannerDiscovery="false"/>
								<inputType id="com.crt.advproject.compiler.input.947432506" superClass="com.crt.advproject.compiler.input"/>
							</tool>
							<tool id="com.crt.advproject.gas.exe.release.1561014943" name="MCU Assembler" superClass="com.crt.advproject.gas.exe.release">
								<option id="com.crt.advproject.gas.thumb.1459081818" name="Thumb mode" superClass="com.crt.advproject.gas.thumb" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.gas.arch.1602967052" name="Architecture" superClass="com.crt.advproject.gas.arch" useByScannerDiscovery="false" value="com.crt.advproject.gas.target.cm7" valueType="enumerated"/>
								<option id="gnu.both.asm.option.flags.crt.2118301934" name="Assembler flags" superClass="gnu.both.asm.option.flags.crt" useByScannerDiscovery="false" value="-c -x assembler-with-cpp -D__NEWLIB__" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.both.asm.option.include.paths.966048605" name="Include paths (-I)" superClass="gnu.both.asm.option.include.paths" useByScannerDiscovery="false" valueType="includePath">
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/board}&quot;"/>
									<listOptionValue builtIn="false" value="&quot;${workspace_loc:/${ProjName}/source}&quot;"/>
								</option>
								<option id="gnu.both.asm.option.warnings.nowarn.171920178" name="Suppress warnings (-W)" superClass="gnu.both.asm.option.warnings.nowarn" useByScannerDiscovery="false"/>
								<option id="gnu.both.asm.option.version.1089329595" name="Announce version (-v)" superClass="gnu.both.asm.option.version" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.fpu.1945099269" name="Floating point" superClass="com.crt.advproject.gas.fpu" useByScannerDiscovery="false" value="com.crt.advproject.gas.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.gas.thumbinterwork.786531919" name="Enable Thumb interworking" superClass="com.crt.advproject.gas.thumbinterwork" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.hdrlib.1893110316" name="Library headers" superClass="com.crt.advproject.gas.hdrlib" useByScannerDiscovery="false" value="com.crt.advproject.gas.hdrlib.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gas.specs.240050447" name="Specs" superClass="com.crt.advproject.gas.specs" useByScannerDiscovery="false" value="com.crt.advproject.gas.specs.newlib" valueType="enumerated"/>
								<option id="com.crt.advproject.gas.config.664118948" name="Obsolete (Config)" superClass="com.crt.advproject.gas.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.gas.store.1242622461" name="Obsolete (Store)" superClass="com.crt.advproject.gas.store" useByScannerDiscovery="false"/>
								<inputType id="cdt.managedbuild.tool.gnu.assembler.input.610929526" superClass="cdt.managedbuild.tool.gnu.assembler.input"/>
								<inputType id="com.crt.advproject.assembler.input.1840792046" name="Additional Assembly Source Files" superClass="com.crt.advproject.assembler.input"/>
							</tool>
							<tool id="com.crt.advproject.link.cpp.exe.release.1908627261" name="MCU C++ Linker" superClass="com.crt.advproject.link.cpp.exe.release">
								<option id="com.crt.advproject.link.cpp.arch.720041521" name="Architecture" superClass="com.crt.advproject.link.cpp.arch" value="com.crt.advproject.link.cpp.target.cm7" valueType="enumerated"/>
								<option id="com.crt.advproject.link.cpp.multicore.slave.557586117" name="Multicore configuration" superClass="com.crt.advproject.link.cpp.multicore.slave"/>
								<option id="gnu.cpp.link.option.nostart.613931232" name="Do not use standard start files (-nostartfiles)" superClass="gnu.cpp.link.option.nostart"/>
								<option id="gnu.cpp.link.option.nodeflibs.1527503481" name="Do not use default libraries (-nodefaultlibs)" superClass="gnu.cpp.link.option.nodeflibs"/>
								<option id="gnu.cpp.link.option.nostdlibs.1763367904" name="No startup or default libs (-nostdlib)" superClass="gnu.cpp.link.option.nostdlibs" value="true" valueType="boolean"/>
								<option id="gnu.cpp.link.option.strip.686653234" name="Omit all symbol information (-s)" superClass="gnu.cpp.link.option.strip"/>
								<option id="gnu.cpp.link.option.libs.357523151" name="Libraries (-l)" superClass="gnu.cpp.link.option.libs"/>
								<option id="gnu.cpp.link.option.paths.1134349891" name="Library search path (-L)" superClass="gnu.cpp.link.option.paths"/>
								<option id="gnu.cpp.link.option.flags.939375396" name="Linker flags" superClass="gnu.cpp.link.option.flags"/>
								<option id="gnu.cpp.link.option.other.114270864" name="Other options (-Xlinker [option])" superClass="gnu.cpp.link.option.other"/>
								<option id="gnu.cpp.link.option.userobjs.529196500" name="Other objects" superClass="gnu.cpp.link.option.userobjs"/>
								<option id="gnu.cpp.link.option.shared.166200473" name="Shared (-shared)" superClass="gnu.cpp.link.option.shared"/>
								<option id="gnu.cpp.link.option.soname.889636191" name="Shared object name (-Wl,-soname=)" superClass="gnu.cpp.link.option.soname"/>
								<option id="gnu.cpp.link.option.implname.993340232" name="Import Library name (-Wl,--out-implib=)" superClass="gnu.cpp.link.option.implname"/>
								<option id="gnu.cpp.link.option.defname.746969775" name="DEF file name (-Wl,--output-def=)" superClass="gnu.cpp.link.option.defname"/>
								<option id="gnu.cpp.link.option.debugging.prof.559849165" name="Generate prof information (-p)" superClass="gnu.cpp.link.option.debugging.prof"/>
								<option id="gnu.cpp.link.option.debugging.gprof.1008220237" name="Generate gprof information (-pg)" superClass="gnu.cpp.link.option.debugging.gprof"/>
								<option id="gnu.cpp.link.option.debugging.codecov.810796498" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.cpp.link.option.debugging.codecov"/>
								<option id="com.crt.advproject.link.cpp.lto.1445709804" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.link.cpp.lto"/>
								<option id="com.crt.advproject.link.cpp.lto.optmization.level.1417725909" name="Link-time optimization level" superClass="com.crt.advproject.link.cpp.lto.optmization.level"/>
								<option id="com.crt.advproject.link.cpp.fpu.772869514" name="Floating point" superClass="com.crt.advproject.link.cpp.fpu" value="com.crt.advproject.link.cpp.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.link.cpp.thumb.1904804520" name="Thumb mode" superClass="com.crt.advproject.link.cpp.thumb"/>
								<option id="com.crt.advproject.link.cpp.manage.1532234158" name="Manage linker script" superClass="com.crt.advproject.link.cpp.manage"/>
								<option id="com.crt.advproject.link.cpp.script.1452588375" name="Linker script" superClass="com.crt.advproject.link.cpp.script"/>
								<option id="com.crt.advproject.link.cpp.scriptdir.1992080399" name="Script path" superClass="com.crt.advproject.link.cpp.scriptdir"/>
								<option id="com.crt.advproject.link.cpp.crpenable.1506218616" name="Enable automatic placement of Code Read Protection field in image" superClass="com.crt.advproject.link.cpp.crpenable"/>
								<option id="com.crt.advproject.link.cpp.flashconfigenable.1283824486" name="Enable automatic placement of Flash Configuration field in image" superClass="com.crt.advproject.link.cpp.flashconfigenable" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.cpp.ecrp.1026842699" name="Enhanced CRP" superClass="com.crt.advproject.link.cpp.ecrp"/>
								<option id="com.crt.advproject.link.cpp.hdrlib.396032199" name="Library" superClass="com.crt.advproject.link.cpp.hdrlib"/>
								<option id="com.crt.advproject.link.cpp.nanofloat.1531724374" name="Enable printf float " superClass="com.crt.advproject.link.cpp.nanofloat"/>
								<option id="com.crt.advproject.link.cpp.nanofloat.scanf.1285609700" name="Enable scanf float " superClass="com.crt.advproject.link.cpp.nanofloat.scanf"/>
								<option id="com.crt.advproject.link.cpp.toram.1585335453" name="Link application to RAM" superClass="com.crt.advproject.link.cpp.toram"/>
								<option id="com.crt.advproject.link.memory.load.image.cpp.1714323208" name="Plain load image" superClass="com.crt.advproject.link.memory.load.image.cpp"/>
								<option id="com.crt.advproject.link.memory.heapAndStack.style.cpp.622380812" name="Heap and Stack placement" superClass="com.crt.advproject.link.memory.heapAndStack.style.cpp"/>
								<option id="com.crt.advproject.link.cpp.stackOffset.517824171" name="Stack offset" superClass="com.crt.advproject.link.cpp.stackOffset"/>
								<option id="com.crt.advproject.link.memory.heapAndStack.cpp.1818840522" name="Heap and Stack options" superClass="com.crt.advproject.link.memory.heapAndStack.cpp"/>
								<option id="com.crt.advproject.link.memory.data.cpp.1223237032" name="Global data placement" superClass="com.crt.advproject.link.memory.data.cpp"/>
								<option id="com.crt.advproject.link.memory.sections.cpp.1768888349" name="Extra linker script input sections" superClass="com.crt.advproject.link.memory.sections.cpp"/>
								<option id="com.crt.advproject.link.cpp.multicore.master.72207062" name="Multicore master" superClass="com.crt.advproject.link.cpp.multicore.master"/>
								<option id="com.crt.advproject.link.cpp.multicore.empty.1322055995" name="No Multicore options for this project" superClass="com.crt.advproject.link.cpp.multicore.empty"/>
								<option id="com.crt.advproject.link.cpp.multicore.master.userobjs.1101279185" name="Slave Objects (not visible)" superClass="com.crt.advproject.link.cpp.multicore.master.userobjs"/>
								<option id="com.crt.advproject.link.cpp.config.1694362191" name="Obsolete (Config)" superClass="com.crt.advproject.link.cpp.config"/>
								<option id="com.crt.advproject.link.cpp.store.362991005" name="Obsolete (Store)" superClass="com.crt.advproject.link.cpp.store"/>
								<option id="com.crt.advproject.link.cpp.securestate.1152854880" name="TrustZone Project Type" superClass="com.crt.advproject.link.cpp.securestate"/>
								<option id="com.crt.advproject.link.cpp.sgstubs.placement.2110323361" name="Secure Gateway Placement" superClass="com.crt.advproject.link.cpp.sgstubs.placement"/>
								<option id="com.crt.advproject.link.cpp.sgstubenable.1037066513" name="Enable generation of Secure Gateway Import Library" superClass="com.crt.advproject.link.cpp.sgstubenable"/>
								<option id="com.crt.advproject.link.cpp.nonsecureobject.1565491366" name="Secure Gateway Import Library" superClass="com.crt.advproject.link.cpp.nonsecureobject"/>
								<option id="com.crt.advproject.link.cpp.inimplib.1577083090" name="Input Secure Gateway Import Library" superClass="com.crt.advproject.link.cpp.inimplib"/>
							</tool>
							<tool id="com.crt.advproject.link.exe.release.171105752" name="MCU Linker" superClass="com.crt.advproject.link.exe.release">
								<option id="com.crt.advproject.link.thumb.1295630033" name="Thumb mode" superClass="com.crt.advproject.link.thumb" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.memory.load.image.1252634157" name="Plain load image" superClass="com.crt.advproject.link.memory.load.image" useByScannerDiscovery="false" value="" valueType="string"/>
								<option defaultValue="com.crt.advproject.heapAndStack.mcuXpressoStyle" id="com.crt.advproject.link.memory.heapAndStack.style.945011975" name="Heap and Stack placement" superClass="com.crt.advproject.link.memory.heapAndStack.style" useByScannerDiscovery="false" valueType="enumerated"/>
								<option id="com.crt.advproject.link.memory.heapAndStack.1579431185" name="Heap and Stack options" superClass="com.crt.advproject.link.memory.heapAndStack" useByScannerDiscovery="false" value="&amp;Heap:Default;Post Data;Default&amp;Stack:Default;End;Default" valueType="string"/>
								<option id="com.crt.advproject.link.memory.data.1829787521" name="Global data placement" superClass="com.crt.advproject.link.memory.data" useByScannerDiscovery="false" value="" valueType="string"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="com.crt.advproject.link.memory.sections.850711446" name="Extra linker script input sections" superClass="com.crt.advproject.link.memory.sections" useByScannerDiscovery="false" valueType="stringList">
									<listOptionValue builtIn="false" value="isd=KEEP(*(CodeQuickAccess));region=SRAM_ITC_cm7;type=.data"/>
									<listOptionValue builtIn="false" value="isd=*(NonCacheable.init);region=NCACHE_REGION;type=.data"/>
									<listOptionValue builtIn="false" value="isd=*(NonCacheable);region=NCACHE_REGION;type=.bss"/>
								</option>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="true" id="com.crt.advproject.link.gcc.multicore.master.userobjs.1063625601" name="Slave Objects (not visible)" superClass="com.crt.advproject.link.gcc.multicore.master.userobjs" useByScannerDiscovery="false" valueType="userObjs"/>
								<option id="com.crt.advproject.link.gcc.multicore.slave.1441731025" name="Multicore configuration" superClass="com.crt.advproject.link.gcc.multicore.slave" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.arch.202790236" name="Architecture" superClass="com.crt.advproject.link.arch" useByScannerDiscovery="false" value="com.crt.advproject.link.target.cm7" valueType="enumerated"/>
								<option id="gnu.c.link.option.nostart.1377261002" name="Do not use standard start files (-nostartfiles)" superClass="gnu.c.link.option.nostart" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.nodeflibs.1411603053" name="Do not use default libraries (-nodefaultlibs)" superClass="gnu.c.link.option.nodeflibs" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.nostdlibs.1556399936" name="No startup or default libs (-nostdlib)" superClass="gnu.c.link.option.nostdlibs" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="gnu.c.link.option.strip.1236965211" name="Omit all symbol information (-s)" superClass="gnu.c.link.option.strip" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.noshared.809884001" name="No shared libraries (-static)" superClass="gnu.c.link.option.noshared" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.libs.1671118582" name="Libraries (-l)" superClass="gnu.c.link.option.libs" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.paths.1078632169" name="Library search path (-L)" superClass="gnu.c.link.option.paths" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.ldflags.1070660593" name="Linker flags" superClass="gnu.c.link.option.ldflags" useByScannerDiscovery="false"/>
								<option IS_BUILTIN_EMPTY="false" IS_VALUE_EMPTY="false" id="gnu.c.link.option.other.461265198" name="Other options (-Xlinker [option])" superClass="gnu.c.link.option.other" useByScannerDiscovery="false" valueType="stringList">
									<listOptionValue builtIn="false" value="-Map=&quot;${BuildArtifactFileBaseName}.map&quot;"/>
									<listOptionValue builtIn="false" value="--gc-sections"/>
									<listOptionValue builtIn="false" value="-print-memory-usage"/>
									<listOptionValue builtIn="false" value="--sort-section=alignment"/>
									<listOptionValue builtIn="false" value="--cref"/>
								</option>
								<option id="gnu.c.link.option.userobjs.1124537713" name="Other objects" superClass="gnu.c.link.option.userobjs" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.shared.1998866460" name="Shared (-shared)" superClass="gnu.c.link.option.shared" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.soname.1928000875" name="Shared object name (-Wl,-soname=)" superClass="gnu.c.link.option.soname" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.implname.587324288" name="Import Library name (-Wl,--out-implib=)" superClass="gnu.c.link.option.implname" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.defname.810450357" name="DEF file name (-Wl,--output-def=)" superClass="gnu.c.link.option.defname" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.debugging.prof.1684773959" name="Generate prof information (-p)" superClass="gnu.c.link.option.debugging.prof" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.debugging.gprof.1632177970" name="Generate gprof information (-pg)" superClass="gnu.c.link.option.debugging.gprof" useByScannerDiscovery="false"/>
								<option id="gnu.c.link.option.debugging.codecov.1451770083" name="Generate gcov information (-ftest-coverage -fprofile-arcs)" superClass="gnu.c.link.option.debugging.codecov" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.lto.1594926593" name="Enable Link-time optimization (-flto)" superClass="com.crt.advproject.link.gcc.lto" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.lto.optmization.level.598202074" name="Link-time optimization level" superClass="com.crt.advproject.link.gcc.lto.optmization.level" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.fpu.860190109" name="Floating point" superClass="com.crt.advproject.link.fpu" useByScannerDiscovery="false" value="com.crt.advproject.link.fpu.fpv5dp.hard" valueType="enumerated"/>
								<option id="com.crt.advproject.link.manage.268325646" name="Manage linker script" superClass="com.crt.advproject.link.manage" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.script.240148737" name="Linker script" superClass="com.crt.advproject.link.script" useByScannerDiscovery="false" value="qr03_boot_Release.ld" valueType="string"/>
								<option id="com.crt.advproject.link.scriptdir.2074148053" name="Script path" superClass="com.crt.advproject.link.scriptdir" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.crpenable.1433610079" name="Enable automatic placement of Code Read Protection field in image" superClass="com.crt.advproject.link.crpenable" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.flashconfigenable.1897629563" name="Enable automatic placement of Flash Configuration field in image" superClass="com.crt.advproject.link.flashconfigenable" useByScannerDiscovery="false" value="true" valueType="boolean"/>
								<option id="com.crt.advproject.link.ecrp.355077539" name="Enhanced CRP" superClass="com.crt.advproject.link.ecrp" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.hdrlib.389278012" name="Library" superClass="com.crt.advproject.link.gcc.hdrlib" useByScannerDiscovery="false" value="com.crt.advproject.gcc.link.hdrlib.newlib.nohost" valueType="enumerated"/>
								<option id="com.crt.advproject.link.gcc.nanofloat.768244288" name="Enable printf float " superClass="com.crt.advproject.link.gcc.nanofloat" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.nanofloat.scanf.197174301" name="Enable scanf float " superClass="com.crt.advproject.link.gcc.nanofloat.scanf" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.toram.1956373309" name="Link application to RAM" superClass="com.crt.advproject.link.toram" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.stackOffset.797924619" name="Stack offset" superClass="com.crt.advproject.link.stackOffset" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.multicore.master.1672021096" name="Multicore master" superClass="com.crt.advproject.link.gcc.multicore.master" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.gcc.multicore.empty.1553218771" name="No Multicore options for this project" superClass="com.crt.advproject.link.gcc.multicore.empty" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.config.353388795" name="Obsolete (Config)" superClass="com.crt.advproject.link.config" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.store.1620004982" name="Obsolete (Store)" superClass="com.crt.advproject.link.store" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.securestate.143055787" name="TrustZone Project Type" superClass="com.crt.advproject.link.securestate" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.sgstubs.placement.350945523" name="Secure Gateway Placement" superClass="com.crt.advproject.link.sgstubs.placement" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.sgstubenable.325938148" name="Enable generation of Secure Gateway Import Library" superClass="com.crt.advproject.link.sgstubenable" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.nonsecureobject.298663503" name="Secure Gateway Import Library" superClass="com.crt.advproject.link.nonsecureobject" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.link.inimplib.1272725045" name="Input Secure Gateway Import Library" superClass="com.crt.advproject.link.inimplib" useByScannerDiscovery="false"/>
								<inputType id="cdt.managedbuild.tool.gnu.c.linker.input.1036956404" superClass="cdt.managedbuild.tool.gnu.c.linker.input">
									<additionalInput kind="additionalinputdependency" paths="$(USER_OBJS)"/>
									<additionalInput kind="additionalinput" paths="$(LIBS)"/>
								</inputType>
							</tool>
							<tool id="com.crt.advproject.tool.debug.release.1930860195" name="MCU Debugger" superClass="com.crt.advproject.tool.debug.release">
								<option id="com.crt.advproject.miscellaneous.end_of_heap.683662124" name="Last used address of the heap" superClass="com.crt.advproject.miscellaneous.end_of_heap" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.miscellaneous.pvHeapStart.644169227" name="First address of the heap" superClass="com.crt.advproject.miscellaneous.pvHeapStart" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.miscellaneous.pvHeapLimit.1882914090" name="Maximum extent of heap" superClass="com.crt.advproject.miscellaneous.pvHeapLimit" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.debugger.security.nonsecureimageenable.853778238" name="Enable pre-programming of Non-Secure Image" superClass="com.crt.advproject.debugger.security.nonsecureimageenable" useByScannerDiscovery="false"/>
								<option id="com.crt.advproject.debugger.security.nonsecureimage.169182159" name="Non-Secure Project" superClass="com.crt.advproject.debugger.security.nonsecureimage" useByScannerDiscovery="false"/>
							</tool>
						</toolChain>
					</folderInfo>
					<sourceEntries>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="component"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="startup"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="CMSIS"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="source"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="utilities"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="drivers"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="device"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="board"/>
						<entry flags="LOCAL|VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="xip"/>
					</sourceEntries>
				</configuration>
			</storageModule>
			<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
		</cconfiguration>
	</storageModule>
	<storageModule moduleId="cdtBuildSystem" version="4.0.0">
		<project id="qr03_boot.null.776234219" name="qr03_boot" projectType="com.crt.advproject.projecttype.exe"/>
	</storageModule>
	<storageModule moduleId="scannerConfiguration">
		<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		<scannerConfigBuildInfo instanceId="com.crt.advproject.config.exe.release.1974876544;com.crt.advproject.config.exe.release.1974876544.;com.crt.advproject.gas.exe.release.1561014943;com.crt.advproject.assembler.input.1840792046">
			<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		</scannerConfigBuildInfo>
		<scannerConfigBuildInfo instanceId="com.crt.advproject.config.exe.debug.684508519;com.crt.advproject.config.exe.debug.684508519.;com.crt.advproject.gas.exe.debug.1844254180;com.crt.advproject.assembler.input.145601640">
			<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		</scannerConfigBuildInfo>
		<scannerConfigBuildInfo instanceId="com.crt.advproject.config.exe.release.1974876544;com.crt.advproject.config.exe.release.1974876544.;com.crt.advproject.gcc.exe.release.621598700;com.crt.advproject.compiler.input.947432506">
			<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		</scannerConfigBuildInfo>
		<scannerConfigBuildInfo instanceId="com.crt.advproject.config.exe.debug.684508519;com.crt.advproject.config.exe.debug.684508519.;com.crt.advproject.gcc.exe.debug.893290723;com.crt.advproject.compiler.input.416572107">
			<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
		</scannerConfigBuildInfo>
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.core.LanguageSettingsProviders"/>
	<storageModule moduleId="com.nxp.mcuxpresso.core.datamodels">
		<sdkName>SDK_2.x_MIMXRT1170-EVK</sdkName>
		<sdkExample>qr03_boot</sdkExample>
		<sdkVersion>2.10.0</sdkVersion>
		<sdkComponents>utility.debug_console_lite.MIMXRT1176;platform.utilities.assert_lite.MIMXRT1176;platform.drivers.clock.MIMXRT1176;platform.drivers.common.MIMXRT1176;platform.devices.MIMXRT1176_CMSIS.MIMXRT1176;component.lpuart_adapter.MIMXRT1176;component.lists.MIMXRT1176;platform.drivers.lpuart.MIMXRT1176;platform.devices.MIMXRT1176_startup.MIMXRT1176;platform.drivers.iomuxc.MIMXRT1176;platform.drivers.igpio.MIMXRT1176;platform.drivers.xip_device.MIMXRT1176;platform.drivers.xip_board.evkmimxrt1170.MIMXRT1176;platform.drivers.pmu_1.MIMXRT1176;platform.drivers.dcdc_soc.MIMXRT1176;platform.drivers.cache_armv7_m7.MIMXRT1176;platform.drivers.anatop_ai.MIMXRT1176;CMSIS_Include_core_cm.MIMXRT1176;platform.utilities.misc_utilities.MIMXRT1176;platform.devices.MIMXRT1176_system.MIMXRT1176;qr03_boot;</sdkComponents>
		<boardId>evkmimxrt1170</boardId>
		<package>MIMXRT1176AVM8A</package>
		<core>cm7</core>
		<coreId>cm7_MIMXRT1176xxxxx</coreId>
	</storageModule>
	<storageModule moduleId="com.crt.config">
		<projectStorage>&lt;?xml version="1.0" encoding="UTF-8"?&gt;&#13;
&lt;TargetConfig&gt;&#13;
&lt;Properties property_3="NXP" property_4="MIMXRT1176xxxxx" property_count="5" version="100300"/&gt;&#13;
&lt;infoList vendor="NXP"&gt;&#13;
&lt;info chip="MIMXRT1176xxxxx" name="MIMXRT1176xxxxx"&gt;&#13;
&lt;chip&gt;&#13;
&lt;name&gt;MIMXRT1176xxxxx&lt;/name&gt;&#13;
&lt;family&gt;MIMXRT1170&lt;/family&gt;&#13;
&lt;vendor&gt;NXP&lt;/vendor&gt;&#13;
&lt;memory can_program="true" id="Flash" is_ro="true" size="0" type="Flash"/&gt;&#13;
&lt;memory id="RAM" size="2048" type="RAM"/&gt;&#13;
&lt;memoryInstance derived_from="Flash" driver="MIMXRT1170_SFDP_QSPI.cfx" edited="true" id="BOARD_FLASH" location="0x30000000" size="0x80000"/&gt;&#13;
&lt;memoryInstance derived_from="RAM" edited="true" id="SRAM_ITC_cm7" location="0x0" size="0x40000"/&gt;&#13;
&lt;memoryInstance derived_from="RAM" edited="true" id="SRAM_DTC_cm7" location="0x20000000" size="0x40000"/&gt;&#13;
&lt;memoryInstance derived_from="RAM" edited="true" id="SRAM_OC1" location="0x20200000" size="0x40000"/&gt;&#13;
&lt;memoryInstance derived_from="RAM" edited="true" id="NCACHE_REGION" location="0x20280000" size="0x80000"/&gt;&#13;
&lt;/chip&gt;&#13;
&lt;processor&gt;&#13;
&lt;name gcc_name="cortex-m4"&gt;Cortex-M4&lt;/name&gt;&#13;
&lt;family&gt;Cortex-M&lt;/family&gt;&#13;
&lt;/processor&gt;&#13;
&lt;processor&gt;&#13;
&lt;name gcc_name="cortex-m7"&gt;Cortex-M7&lt;/name&gt;&#13;
&lt;family&gt;Cortex-M&lt;/family&gt;&#13;
&lt;/processor&gt;&#13;
&lt;/info&gt;&#13;
&lt;/infoList&gt;&#13;
&lt;/TargetConfig&gt;</projectStorage>
	</storageModule>
	<storageModule moduleId="refreshScope" versionNumber="2">
		<configuration configurationName="Debug">
			<resource resourceType="PROJECT" workspacePath="/qr03_boot"/>
		</configuration>
		<configuration configurationName="Release">
			<resource resourceType="PROJECT" workspacePath="/qr03_boot"/>
		</configuration>
	</storageModule>
	<storageModule moduleId="org.eclipse.cdt.make.core.buildtargets"/>
</cproject>