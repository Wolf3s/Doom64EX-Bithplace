
#ifndef __DOOM64EX_KEXLIB_H__
#define __DOOM64EX_KEXLIB_H__

#define KEXAPI extern

#ifdef __cplusplus
# define KEX_C_BEGIN extern "C" {
# define KEX_C_END }
#else
# define KEX_C_BEGIN
# define KEX_C_END
#endif

#endif //__DOOM64EX_KEXLIB_H__
