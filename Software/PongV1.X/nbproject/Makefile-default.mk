#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=class/ball.c class/paddle.c class/factory.c class/score.c class/gameParameters.c class/menu.c libraries/arialNarrow_12ptBitmaps.c libraries/lcd_highlevel.c libraries/lcd_lowlevel.c stateMachine/sleepSM.c stateMachine/touchScreenSM.c stateMachine/display.c stateMachine/gameController.c xf/xf.c configuration_bits.c main.c gameFunction.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/class/ball.p1 ${OBJECTDIR}/class/paddle.p1 ${OBJECTDIR}/class/factory.p1 ${OBJECTDIR}/class/score.p1 ${OBJECTDIR}/class/gameParameters.p1 ${OBJECTDIR}/class/menu.p1 ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1 ${OBJECTDIR}/libraries/lcd_highlevel.p1 ${OBJECTDIR}/libraries/lcd_lowlevel.p1 ${OBJECTDIR}/stateMachine/sleepSM.p1 ${OBJECTDIR}/stateMachine/touchScreenSM.p1 ${OBJECTDIR}/stateMachine/display.p1 ${OBJECTDIR}/stateMachine/gameController.p1 ${OBJECTDIR}/xf/xf.p1 ${OBJECTDIR}/configuration_bits.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/gameFunction.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/class/ball.p1.d ${OBJECTDIR}/class/paddle.p1.d ${OBJECTDIR}/class/factory.p1.d ${OBJECTDIR}/class/score.p1.d ${OBJECTDIR}/class/gameParameters.p1.d ${OBJECTDIR}/class/menu.p1.d ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d ${OBJECTDIR}/libraries/lcd_highlevel.p1.d ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d ${OBJECTDIR}/stateMachine/sleepSM.p1.d ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d ${OBJECTDIR}/stateMachine/display.p1.d ${OBJECTDIR}/stateMachine/gameController.p1.d ${OBJECTDIR}/xf/xf.p1.d ${OBJECTDIR}/configuration_bits.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/gameFunction.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/class/ball.p1 ${OBJECTDIR}/class/paddle.p1 ${OBJECTDIR}/class/factory.p1 ${OBJECTDIR}/class/score.p1 ${OBJECTDIR}/class/gameParameters.p1 ${OBJECTDIR}/class/menu.p1 ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1 ${OBJECTDIR}/libraries/lcd_highlevel.p1 ${OBJECTDIR}/libraries/lcd_lowlevel.p1 ${OBJECTDIR}/stateMachine/sleepSM.p1 ${OBJECTDIR}/stateMachine/touchScreenSM.p1 ${OBJECTDIR}/stateMachine/display.p1 ${OBJECTDIR}/stateMachine/gameController.p1 ${OBJECTDIR}/xf/xf.p1 ${OBJECTDIR}/configuration_bits.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/gameFunction.p1

# Source Files
SOURCEFILES=class/ball.c class/paddle.c class/factory.c class/score.c class/gameParameters.c class/menu.c libraries/arialNarrow_12ptBitmaps.c libraries/lcd_highlevel.c libraries/lcd_lowlevel.c stateMachine/sleepSM.c stateMachine/touchScreenSM.c stateMachine/display.c stateMachine/gameController.c xf/xf.c configuration_bits.c main.c gameFunction.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18LF25K22
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/class/ball.p1: class/ball.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/ball.p1.d 
	@${RM} ${OBJECTDIR}/class/ball.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/ball.p1 class/ball.c 
	@-${MV} ${OBJECTDIR}/class/ball.d ${OBJECTDIR}/class/ball.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/ball.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/paddle.p1: class/paddle.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/paddle.p1.d 
	@${RM} ${OBJECTDIR}/class/paddle.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/paddle.p1 class/paddle.c 
	@-${MV} ${OBJECTDIR}/class/paddle.d ${OBJECTDIR}/class/paddle.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/paddle.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/factory.p1: class/factory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/factory.p1.d 
	@${RM} ${OBJECTDIR}/class/factory.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/factory.p1 class/factory.c 
	@-${MV} ${OBJECTDIR}/class/factory.d ${OBJECTDIR}/class/factory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/factory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/score.p1: class/score.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/score.p1.d 
	@${RM} ${OBJECTDIR}/class/score.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/score.p1 class/score.c 
	@-${MV} ${OBJECTDIR}/class/score.d ${OBJECTDIR}/class/score.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/score.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/gameParameters.p1: class/gameParameters.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/gameParameters.p1.d 
	@${RM} ${OBJECTDIR}/class/gameParameters.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/gameParameters.p1 class/gameParameters.c 
	@-${MV} ${OBJECTDIR}/class/gameParameters.d ${OBJECTDIR}/class/gameParameters.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/gameParameters.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/menu.p1: class/menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/menu.p1.d 
	@${RM} ${OBJECTDIR}/class/menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/menu.p1 class/menu.c 
	@-${MV} ${OBJECTDIR}/class/menu.d ${OBJECTDIR}/class/menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1: libraries/arialNarrow_12ptBitmaps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d 
	@${RM} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1 libraries/arialNarrow_12ptBitmaps.c 
	@-${MV} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.d ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libraries/lcd_highlevel.p1: libraries/lcd_highlevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/lcd_highlevel.p1.d 
	@${RM} ${OBJECTDIR}/libraries/lcd_highlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/libraries/lcd_highlevel.p1 libraries/lcd_highlevel.c 
	@-${MV} ${OBJECTDIR}/libraries/lcd_highlevel.d ${OBJECTDIR}/libraries/lcd_highlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libraries/lcd_highlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libraries/lcd_lowlevel.p1: libraries/lcd_lowlevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d 
	@${RM} ${OBJECTDIR}/libraries/lcd_lowlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/libraries/lcd_lowlevel.p1 libraries/lcd_lowlevel.c 
	@-${MV} ${OBJECTDIR}/libraries/lcd_lowlevel.d ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/sleepSM.p1: stateMachine/sleepSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/sleepSM.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/sleepSM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/sleepSM.p1 stateMachine/sleepSM.c 
	@-${MV} ${OBJECTDIR}/stateMachine/sleepSM.d ${OBJECTDIR}/stateMachine/sleepSM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/sleepSM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/touchScreenSM.p1: stateMachine/touchScreenSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/touchScreenSM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/touchScreenSM.p1 stateMachine/touchScreenSM.c 
	@-${MV} ${OBJECTDIR}/stateMachine/touchScreenSM.d ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/display.p1: stateMachine/display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/display.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/display.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/display.p1 stateMachine/display.c 
	@-${MV} ${OBJECTDIR}/stateMachine/display.d ${OBJECTDIR}/stateMachine/display.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/display.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/gameController.p1: stateMachine/gameController.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/gameController.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/gameController.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/gameController.p1 stateMachine/gameController.c 
	@-${MV} ${OBJECTDIR}/stateMachine/gameController.d ${OBJECTDIR}/stateMachine/gameController.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/gameController.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/xf/xf.p1: xf/xf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xf" 
	@${RM} ${OBJECTDIR}/xf/xf.p1.d 
	@${RM} ${OBJECTDIR}/xf/xf.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/xf/xf.p1 xf/xf.c 
	@-${MV} ${OBJECTDIR}/xf/xf.d ${OBJECTDIR}/xf/xf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/xf/xf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/configuration_bits.p1: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.p1.d 
	@${RM} ${OBJECTDIR}/configuration_bits.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/configuration_bits.p1 configuration_bits.c 
	@-${MV} ${OBJECTDIR}/configuration_bits.d ${OBJECTDIR}/configuration_bits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/configuration_bits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/gameFunction.p1: gameFunction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/gameFunction.p1.d 
	@${RM} ${OBJECTDIR}/gameFunction.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/gameFunction.p1 gameFunction.c 
	@-${MV} ${OBJECTDIR}/gameFunction.d ${OBJECTDIR}/gameFunction.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/gameFunction.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/class/ball.p1: class/ball.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/ball.p1.d 
	@${RM} ${OBJECTDIR}/class/ball.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/ball.p1 class/ball.c 
	@-${MV} ${OBJECTDIR}/class/ball.d ${OBJECTDIR}/class/ball.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/ball.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/paddle.p1: class/paddle.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/paddle.p1.d 
	@${RM} ${OBJECTDIR}/class/paddle.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/paddle.p1 class/paddle.c 
	@-${MV} ${OBJECTDIR}/class/paddle.d ${OBJECTDIR}/class/paddle.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/paddle.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/factory.p1: class/factory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/factory.p1.d 
	@${RM} ${OBJECTDIR}/class/factory.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/factory.p1 class/factory.c 
	@-${MV} ${OBJECTDIR}/class/factory.d ${OBJECTDIR}/class/factory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/factory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/score.p1: class/score.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/score.p1.d 
	@${RM} ${OBJECTDIR}/class/score.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/score.p1 class/score.c 
	@-${MV} ${OBJECTDIR}/class/score.d ${OBJECTDIR}/class/score.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/score.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/gameParameters.p1: class/gameParameters.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/gameParameters.p1.d 
	@${RM} ${OBJECTDIR}/class/gameParameters.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/gameParameters.p1 class/gameParameters.c 
	@-${MV} ${OBJECTDIR}/class/gameParameters.d ${OBJECTDIR}/class/gameParameters.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/gameParameters.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/class/menu.p1: class/menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/class" 
	@${RM} ${OBJECTDIR}/class/menu.p1.d 
	@${RM} ${OBJECTDIR}/class/menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/class/menu.p1 class/menu.c 
	@-${MV} ${OBJECTDIR}/class/menu.d ${OBJECTDIR}/class/menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/class/menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1: libraries/arialNarrow_12ptBitmaps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d 
	@${RM} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1 libraries/arialNarrow_12ptBitmaps.c 
	@-${MV} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.d ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libraries/arialNarrow_12ptBitmaps.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libraries/lcd_highlevel.p1: libraries/lcd_highlevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/lcd_highlevel.p1.d 
	@${RM} ${OBJECTDIR}/libraries/lcd_highlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/libraries/lcd_highlevel.p1 libraries/lcd_highlevel.c 
	@-${MV} ${OBJECTDIR}/libraries/lcd_highlevel.d ${OBJECTDIR}/libraries/lcd_highlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libraries/lcd_highlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/libraries/lcd_lowlevel.p1: libraries/lcd_lowlevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/libraries" 
	@${RM} ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d 
	@${RM} ${OBJECTDIR}/libraries/lcd_lowlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/libraries/lcd_lowlevel.p1 libraries/lcd_lowlevel.c 
	@-${MV} ${OBJECTDIR}/libraries/lcd_lowlevel.d ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/libraries/lcd_lowlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/sleepSM.p1: stateMachine/sleepSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/sleepSM.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/sleepSM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/sleepSM.p1 stateMachine/sleepSM.c 
	@-${MV} ${OBJECTDIR}/stateMachine/sleepSM.d ${OBJECTDIR}/stateMachine/sleepSM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/sleepSM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/touchScreenSM.p1: stateMachine/touchScreenSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/touchScreenSM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/touchScreenSM.p1 stateMachine/touchScreenSM.c 
	@-${MV} ${OBJECTDIR}/stateMachine/touchScreenSM.d ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/touchScreenSM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/display.p1: stateMachine/display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/display.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/display.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/display.p1 stateMachine/display.c 
	@-${MV} ${OBJECTDIR}/stateMachine/display.d ${OBJECTDIR}/stateMachine/display.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/display.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/stateMachine/gameController.p1: stateMachine/gameController.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/stateMachine" 
	@${RM} ${OBJECTDIR}/stateMachine/gameController.p1.d 
	@${RM} ${OBJECTDIR}/stateMachine/gameController.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/stateMachine/gameController.p1 stateMachine/gameController.c 
	@-${MV} ${OBJECTDIR}/stateMachine/gameController.d ${OBJECTDIR}/stateMachine/gameController.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/stateMachine/gameController.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/xf/xf.p1: xf/xf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/xf" 
	@${RM} ${OBJECTDIR}/xf/xf.p1.d 
	@${RM} ${OBJECTDIR}/xf/xf.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/xf/xf.p1 xf/xf.c 
	@-${MV} ${OBJECTDIR}/xf/xf.d ${OBJECTDIR}/xf/xf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/xf/xf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/configuration_bits.p1: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.p1.d 
	@${RM} ${OBJECTDIR}/configuration_bits.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/configuration_bits.p1 configuration_bits.c 
	@-${MV} ${OBJECTDIR}/configuration_bits.d ${OBJECTDIR}/configuration_bits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/configuration_bits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/gameFunction.p1: gameFunction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/gameFunction.p1.d 
	@${RM} ${OBJECTDIR}/gameFunction.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto -Xparser -Wno-conversion     -o ${OBJECTDIR}/gameFunction.p1 gameFunction.c 
	@-${MV} ${OBJECTDIR}/gameFunction.d ${OBJECTDIR}/gameFunction.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/gameFunction.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../../../../../../Program Files/Microchip/xc8/v2.32/pic/include/proc" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PongV1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
