
EXE_FILE=RgbToNv12
if [ -f ${EXE_FILE} ]; then
    rm ${EXE_FILE}
fi

gcc \
    ../YuvLib/YuvLibFile.c ../YuvLib/YuvLibRgb.c \
    RgbToNv12App.c \
    -o ${EXE_FILE} \
    -I ../YuvLib

./${EXE_FILE}

