/* See md5.c for explanation and copyright information.  */

/*
 * $FreeBSD: src/contrib/cvs/lib/md5.h,v 1.2 1999/12/11 15:10:02 peter Exp $
 */

#ifndef MD5_H
#define MD5_H

/* Unlike previous versions of this code, uint32 need not be exactly
   32 bits, merely 32 bits or more.  Choosing a data type which is 32
   bits instead of 64 is not important; speed is considerably more
   important.  ANSI guarantees that "unsigned long" will be big enough,
   and always using it seems to have few disadvantages.  */
typedef unsigned long cvs_uint32;

struct cvs_MD5Context {
	cvs_uint32 buf[4];
	cvs_uint32 bits[2];
	unsigned char in[64];
};

void cvs_MD5Update(struct cvs_MD5Context *ctx, unsigned char const *buf, unsigned len);
void cvs_MD5Final (unsigned char digest[16], struct cvs_MD5Context *ctx);
void cvs_MD5Transform (cvs_uint32 buf[4], const unsigned char inraw[64]);
void cvs_MD5Init (struct cvs_MD5Context *ctx);

//void cvs_MD5Init PROTO ((struct cvs_MD5Context *context));

//void cvs_MD5Update PROTO ((struct cvs_MD5Context *context,
//			   unsigned char const *buf, unsigned len));
//void cvs_MD5Final PROTO ((unsigned char digest[16],  struct cvs_MD5Context *context));
//void cvs_MD5Transform PROTO ((cvs_uint32 buf[4], const unsigned char in[64]));

static void putu32 (cvs_uint32 data, unsigned char *addr);
static cvs_uint32 getu32 (const unsigned char *addr);

#endif /* !MD5_H */
