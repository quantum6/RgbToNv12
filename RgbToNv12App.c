
#include "YuvLibFile.h"
#include "YuvLibRgb.h"

#define FRAME_WIDTH  1280
#define FRAME_HEIGHT  720
#define PIXEL_SIZE      3
#define BLOCK_SIZE    120

#define FILE_NAME_SIZE 256

int main(int argc, char** argv)
{
    char caRgbFile[FILE_NAME_SIZE] = {0};
    int nRgbSize = FRAME_WIDTH*FRAME_HEIGHT*PIXEL_SIZE;
    char* pRgb = (char*)malloc(nRgbSize);
    
    char caNv12File[FILE_NAME_SIZE] = {0};
    int nNv12Size = (int)(FRAME_WIDTH*FRAME_HEIGHT*1.5);
    char* pNv12 = (char*)malloc(nNv12Size);
    
    YUV_CreateFileNameFrame(caRgbFile, "../RgbCreater/Rgb", FRAME_WIDTH, FRAME_HEIGHT);
    YUV_ReadFromFile(caRgbFile, pRgb, nRgbSize);
    
    YUV_RgbToNv12(pRgb, PIXEL_SIZE,
              FRAME_WIDTH, 
              FRAME_HEIGHT,
              pNv12);
              
    YUV_CreateFileNameFrame(caNv12File, "Nv12", FRAME_WIDTH, FRAME_HEIGHT);
    YUV_WriteToFile(caNv12File, pNv12, nNv12Size);
              
    return 0;
}


