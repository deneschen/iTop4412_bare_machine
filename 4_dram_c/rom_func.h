#ifndef ROM_FUNC_H
#define ROM_FUNC_H

typedef int copy_from_sd(int SrcBlock, int NumofSrcBlock, void *DstByte);
typedef int copy_from_emmc(int SrcBlock, void *DstByte);
typedef void emmc_end(void);

#endif
