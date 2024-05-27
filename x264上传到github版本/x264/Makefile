NAME = x264
SRCS = 	main.c resources.S \
		../common/printf/printf.c \
		../common/math/math.c \
		../common/strings/strings.c \
		../common/fs/fs.c \
		../common/malloc/my_malloc.c

SRCS += common/osdep.c common/base.c common/cpu.c common/tables.c \
       	encoder/api.c

SRCS += common/mc.c common/predict.c common/pixel.c common/macroblock.c \
		common/frame.c common/dct.c common/cabac.c \
		common/common.c common/rectangle.c \
		common/set.c common/quant.c common/deblock.c common/vlc.c \
		common/mvpred.c common/bitstream.c \
		encoder/analyse.c encoder/me.c encoder/ratecontrol.c \
		encoder/set.c encoder/macroblock.c encoder/cabac.c \
		encoder/cavlc.c encoder/encoder.c encoder/lookahead.c

SRCS += ../common/soft-fp/mulsf3.c  ../common/soft-fp/muldf3.c  \
		../common/soft-fp/divsf3.c  ../common/soft-fp/divdf3.c  \
		../common/soft-fp/addsf3.c  ../common/soft-fp/adddf3.c  \
		../common/soft-fp/subsf3.c  ../common/soft-fp/subdf3.c  \
		../common/soft-fp/extendsfdf2.c \
		../common/soft-fp/truncdfsf2.c  \
		../common/soft-fp/fixsfsi.c ../common/soft-fp/fixdfsi.c \
		../common/soft-fp/fixsfdi.c ../common/soft-fp/fixdfdi.c \
		../common/soft-fp/fixsfti.c ../common/soft-fp/fixdfti.c \
		../common/soft-fp/fixunssfsi.c ../common/soft-fp/fixunsdfsi.c \
		../common/soft-fp/fixunssfdi.c ../common/soft-fp/fixunsdfdi.c \
		../common/soft-fp/fixunssfti.c ../common/soft-fp/fixunsdfti.c \
		../common/soft-fp/floatsisf.c    ../common/soft-fp/floatsidf.c    \
		../common/soft-fp/floatdisf.c    ../common/soft-fp/floatdidf.c    \
		../common/soft-fp/floatunsisf.c  ../common/soft-fp/floatunsidf.c  \
		../common/soft-fp/floatundisf.c  ../common/soft-fp/floatundidf.c  \
		../common/soft-fp/eqsf2.c   ../common/soft-fp/eqdf2.c   \
		../common/soft-fp/gesf2.c   ../common/soft-fp/gedf2.c   \
		../common/soft-fp/lesf2.c   ../common/soft-fp/ledf2.c   \
		../common/soft-fp/negsf2.c  ../common/soft-fp/negdf2.c

include $(AM_HOME)/Makefile

