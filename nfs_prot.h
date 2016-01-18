/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NFS_PROT_H_RPCGEN
#define _NFS_PROT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"
#define NFS_PORT 2049
#define NFS_MAXDATA 8192
#define NFS_MAXPATHLEN 1024
#define NFS_MAXNAMLEN 255
#define NFS_FHSIZE 32
#define NFS_COOKIESIZE 4
#define NFS_FIFO_DEV -1
#define NFSMODE_FMT 0170000
#define NFSMODE_DIR 0040000
#define NFSMODE_CHR 0020000
#define NFSMODE_BLK 0060000
#define NFSMODE_REG 0100000
#define NFSMODE_LNK 0120000
#define NFSMODE_SOCK 0140000
#define NFSMODE_FIFO 0010000

enum nfsstat {
	NFS_OK = 0,
	NFSERR_PERM = 1,
	NFSERR_NOENT = 2,
	NFSERR_IO = 5,
	NFSERR_NXIO = 6,
	NFSERR_ACCES = 13,
	NFSERR_EXIST = 17,
	NFSERR_XDEV = 18,
	NFSERR_NODEV = 19,
	NFSERR_NOTDIR = 20,
	NFSERR_ISDIR = 21,
	NFSERR_INVAL = 22,
	NFSERR_FBIG = 27,
	NFSERR_NOSPC = 28,
	NFSERR_ROFS = 30,
	NFSERR_OPNOTSUPP = 45,
	NFSERR_NAMETOOLONG = 63,
	NFSERR_NOTEMPTY = 66,
	NFSERR_DQUOT = 69,
	NFSERR_STALE = 70,
	NFSERR_REMOTE = 71,
	NFSERR_WFLUSH = 72,
};
typedef enum nfsstat nfsstat;

enum ftype {
	NFNON = 0,
	NFREG = 1,
	NFDIR = 2,
	NFBLK = 3,
	NFCHR = 4,
	NFLNK = 5,
	NFSOCK = 6,
	NFBAD = 7,
	NFFIFO = 8,
};
typedef enum ftype ftype;

struct nfs_fh {
	char data[NFS_FHSIZE];
};
typedef struct nfs_fh nfs_fh;

struct nfstime {
	u_int seconds;
	u_int useconds;
};
typedef struct nfstime nfstime;

struct fattr {
	ftype type;
	u_int mode;
	u_int nlink;
	u_int uid;
	u_int gid;
	u_int size;
	u_int blocksize;
	u_int rdev;
	u_int blocks;
	u_int fsid;
	u_int fileid;
	nfstime atime;
	nfstime mtime;
	nfstime ctime;
};
typedef struct fattr fattr;

typedef char *filename;

typedef char *nfspath;

struct diropargs {
	nfs_fh dir;
	filename name;
};
typedef struct diropargs diropargs;

struct diropokres {
	nfs_fh file;
	fattr attributes;
};
typedef struct diropokres diropokres;

struct diropres {
	nfsstat status;
	union {
		diropokres diropres;
	} diropres_u;
};
typedef struct diropres diropres;

struct readargs {
	nfs_fh file;
	u_int offset;
	u_int count;
	u_int totalcount;
};
typedef struct readargs readargs;

struct readokres {
	fattr attributes;
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct readokres readokres;

struct readres {
	nfsstat status;
	union {
		readokres reply;
	} readres_u;
};
typedef struct readres readres;
#define NFS3_FHSIZE 64
#define NFS3_COOKIEVERFSIZE 8
#define NFS3_CREATEVERFSIZE 8
#define NFS3_WRITEVERFSIZE 8

typedef u_int64_t uint64;

typedef int64_t int64;

typedef u_int uint32;

typedef int int32;

typedef char *filename3;

typedef char *nfspath3;

typedef uint64 fileid3;

typedef uint64 cookie3;

typedef char cookieverf3[NFS3_COOKIEVERFSIZE];

typedef char createverf3[NFS3_CREATEVERFSIZE];

typedef char writeverf3[NFS3_WRITEVERFSIZE];

typedef uint32 uid3;

typedef uint32 gid3;

typedef uint64 size3;

typedef uint64 offset3;

typedef uint32 mode3;

typedef uint32 count3;

enum nfsstat3 {
	NFS3_OK = 0,
	NFS3ERR_PERM = 1,
	NFS3ERR_NOENT = 2,
	NFS3ERR_IO = 5,
	NFS3ERR_NXIO = 6,
	NFS3ERR_ACCES = 13,
	NFS3ERR_EXIST = 17,
	NFS3ERR_XDEV = 18,
	NFS3ERR_NODEV = 19,
	NFS3ERR_NOTDIR = 20,
	NFS3ERR_ISDIR = 21,
	NFS3ERR_INVAL = 22,
	NFS3ERR_FBIG = 27,
	NFS3ERR_NOSPC = 28,
	NFS3ERR_ROFS = 30,
	NFS3ERR_MLINK = 31,
	NFS3ERR_NAMETOOLONG = 63,
	NFS3ERR_NOTEMPTY = 66,
	NFS3ERR_DQUOT = 69,
	NFS3ERR_STALE = 70,
	NFS3ERR_REMOTE = 71,
	NFS3ERR_BADHANDLE = 10001,
	NFS3ERR_NOT_SYNC = 10002,
	NFS3ERR_BAD_COOKIE = 10003,
	NFS3ERR_NOTSUPP = 10004,
	NFS3ERR_TOOSMALL = 10005,
	NFS3ERR_SERVERFAULT = 10006,
	NFS3ERR_BADTYPE = 10007,
	NFS3ERR_JUKEBOX = 10008,
};
typedef enum nfsstat3 nfsstat3;

enum ftype3 {
	NF3REG = 1,
	NF3DIR = 2,
	NF3BLK = 3,
	NF3CHR = 4,
	NF3LNK = 5,
	NF3SOCK = 6,
	NF3FIFO = 7,
};
typedef enum ftype3 ftype3;

struct specdata3 {
	uint32 specdata1;
	uint32 specdata2;
};
typedef struct specdata3 specdata3;

struct nfs_fh3 {
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct nfs_fh3 nfs_fh3;

struct nfstime3 {
	uint32 seconds;
	uint32 nseconds;
};
typedef struct nfstime3 nfstime3;

struct fattr3 {
	ftype3 type;
	mode3 mode;
	uint32 nlink;
	uid3 uid;
	gid3 gid;
	size3 size;
	size3 used;
	specdata3 rdev;
	uint64 fsid;
	fileid3 fileid;
	nfstime3 atime;
	nfstime3 mtime;
	nfstime3 ctime;
};
typedef struct fattr3 fattr3;

struct post_op_attr {
	bool_t attributes_follow;
	union {
		fattr3 attributes;
	} post_op_attr_u;
};
typedef struct post_op_attr post_op_attr;

struct wcc_attr {
	size3 size;
	nfstime3 mtime;
	nfstime3 ctime;
};
typedef struct wcc_attr wcc_attr;

struct pre_op_attr {
	bool_t attributes_follow;
	union {
		wcc_attr attributes;
	} pre_op_attr_u;
};
typedef struct pre_op_attr pre_op_attr;

struct wcc_data {
	pre_op_attr before;
	post_op_attr after;
};
typedef struct wcc_data wcc_data;

struct diropargs3 {
	nfs_fh3 dir;
	filename3 name;
};
typedef struct diropargs3 diropargs3;

struct LOOKUP3args {
	diropargs3 what;
};
typedef struct LOOKUP3args LOOKUP3args;

struct LOOKUP3resok {
	nfs_fh3 object;
	post_op_attr obj_attributes;
	post_op_attr dir_attributes;
};
typedef struct LOOKUP3resok LOOKUP3resok;

struct LOOKUP3resfail {
	post_op_attr dir_attributes;
};
typedef struct LOOKUP3resfail LOOKUP3resfail;

struct LOOKUP3res {
	nfsstat3 status;
	union {
		LOOKUP3resok resok;
		LOOKUP3resfail resfail;
	} LOOKUP3res_u;
};
typedef struct LOOKUP3res LOOKUP3res;

struct READ3args {
	nfs_fh3 file;
	offset3 offset;
	count3 count;
};
typedef struct READ3args READ3args;

struct READ3resok {
	post_op_attr file_attributes;
	count3 count;
	bool_t eof;
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct READ3resok READ3resok;

struct READ3resfail {
	post_op_attr file_attributes;
};
typedef struct READ3resfail READ3resfail;

struct READ3res {
	nfsstat status;
	union {
		READ3resok resok;
		READ3resfail resfail;
	} READ3res_u;
};
typedef struct READ3res READ3res;

#define NFS_PROGRAM 100003
#define NFS_VERSION 2

#if defined(__STDC__) || defined(__cplusplus)
#define NFSPROC_NULL 0
extern  void * nfsproc_null_2(void *, CLIENT *);
extern  void * nfsproc_null_2_svc(void *, struct svc_req *);
#define NFSPROC_LOOKUP 4
extern  diropres * nfsproc_lookup_2(diropargs *, CLIENT *);
extern  diropres * nfsproc_lookup_2_svc(diropargs *, struct svc_req *);
#define NFSPROC_READ 6
extern  readres * nfsproc_read_2(readargs *, CLIENT *);
extern  readres * nfsproc_read_2_svc(readargs *, struct svc_req *);
extern int nfs_program_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define NFSPROC_NULL 0
extern  void * nfsproc_null_2();
extern  void * nfsproc_null_2_svc();
#define NFSPROC_LOOKUP 4
extern  diropres * nfsproc_lookup_2();
extern  diropres * nfsproc_lookup_2_svc();
#define NFSPROC_READ 6
extern  readres * nfsproc_read_2();
extern  readres * nfsproc_read_2_svc();
extern int nfs_program_2_freeresult ();
#endif /* K&R C */

#define NFS3_PROGRAM 100003
#define NFS_V3 3

#if defined(__STDC__) || defined(__cplusplus)
#define NFSPROC3_NULL 0
extern  void * nfsproc3_null_3(void *, CLIENT *);
extern  void * nfsproc3_null_3_svc(void *, struct svc_req *);
#define NFSPROC3_LOOKUP 3
extern  LOOKUP3res * nfsproc3_lookup_3(LOOKUP3args *, CLIENT *);
extern  LOOKUP3res * nfsproc3_lookup_3_svc(LOOKUP3args *, struct svc_req *);
#define NFSPROC3_READ 6
extern  READ3res * nfsproc3_read_3(READ3args *, CLIENT *);
extern  READ3res * nfsproc3_read_3_svc(READ3args *, struct svc_req *);
extern int nfs3_program_3_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define NFSPROC3_NULL 0
extern  void * nfsproc3_null_3();
extern  void * nfsproc3_null_3_svc();
#define NFSPROC3_LOOKUP 3
extern  LOOKUP3res * nfsproc3_lookup_3();
extern  LOOKUP3res * nfsproc3_lookup_3_svc();
#define NFSPROC3_READ 6
extern  READ3res * nfsproc3_read_3();
extern  READ3res * nfsproc3_read_3_svc();
extern int nfs3_program_3_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_nfsstat (XDR *, nfsstat*);
extern  bool_t xdr_ftype (XDR *, ftype*);
extern  bool_t xdr_nfs_fh (XDR *, nfs_fh*);
extern  bool_t xdr_nfstime (XDR *, nfstime*);
extern  bool_t xdr_fattr (XDR *, fattr*);
extern  bool_t xdr_filename (XDR *, filename*);
extern  bool_t xdr_nfspath (XDR *, nfspath*);
extern  bool_t xdr_diropargs (XDR *, diropargs*);
extern  bool_t xdr_diropokres (XDR *, diropokres*);
extern  bool_t xdr_diropres (XDR *, diropres*);
extern  bool_t xdr_readargs (XDR *, readargs*);
extern  bool_t xdr_readokres (XDR *, readokres*);
extern  bool_t xdr_readres (XDR *, readres*);
extern  bool_t xdr_uint64 (XDR *, uint64*);
extern  bool_t xdr_int64 (XDR *, int64*);
extern  bool_t xdr_uint32 (XDR *, uint32*);
extern  bool_t xdr_int32 (XDR *, int32*);
extern  bool_t xdr_filename3 (XDR *, filename3*);
extern  bool_t xdr_nfspath3 (XDR *, nfspath3*);
extern  bool_t xdr_fileid3 (XDR *, fileid3*);
extern  bool_t xdr_cookie3 (XDR *, cookie3*);
extern  bool_t xdr_cookieverf3 (XDR *, cookieverf3);
extern  bool_t xdr_createverf3 (XDR *, createverf3);
extern  bool_t xdr_writeverf3 (XDR *, writeverf3);
extern  bool_t xdr_uid3 (XDR *, uid3*);
extern  bool_t xdr_gid3 (XDR *, gid3*);
extern  bool_t xdr_size3 (XDR *, size3*);
extern  bool_t xdr_offset3 (XDR *, offset3*);
extern  bool_t xdr_mode3 (XDR *, mode3*);
extern  bool_t xdr_count3 (XDR *, count3*);
extern  bool_t xdr_nfsstat3 (XDR *, nfsstat3*);
extern  bool_t xdr_ftype3 (XDR *, ftype3*);
extern  bool_t xdr_specdata3 (XDR *, specdata3*);
extern  bool_t xdr_nfs_fh3 (XDR *, nfs_fh3*);
extern  bool_t xdr_nfstime3 (XDR *, nfstime3*);
extern  bool_t xdr_fattr3 (XDR *, fattr3*);
extern  bool_t xdr_post_op_attr (XDR *, post_op_attr*);
extern  bool_t xdr_wcc_attr (XDR *, wcc_attr*);
extern  bool_t xdr_pre_op_attr (XDR *, pre_op_attr*);
extern  bool_t xdr_wcc_data (XDR *, wcc_data*);
extern  bool_t xdr_diropargs3 (XDR *, diropargs3*);
extern  bool_t xdr_LOOKUP3args (XDR *, LOOKUP3args*);
extern  bool_t xdr_LOOKUP3resok (XDR *, LOOKUP3resok*);
extern  bool_t xdr_LOOKUP3resfail (XDR *, LOOKUP3resfail*);
extern  bool_t xdr_LOOKUP3res (XDR *, LOOKUP3res*);
extern  bool_t xdr_READ3args (XDR *, READ3args*);
extern  bool_t xdr_READ3resok (XDR *, READ3resok*);
extern  bool_t xdr_READ3resfail (XDR *, READ3resfail*);
extern  bool_t xdr_READ3res (XDR *, READ3res*);

#else /* K&R C */
extern bool_t xdr_nfsstat ();
extern bool_t xdr_ftype ();
extern bool_t xdr_nfs_fh ();
extern bool_t xdr_nfstime ();
extern bool_t xdr_fattr ();
extern bool_t xdr_filename ();
extern bool_t xdr_nfspath ();
extern bool_t xdr_diropargs ();
extern bool_t xdr_diropokres ();
extern bool_t xdr_diropres ();
extern bool_t xdr_readargs ();
extern bool_t xdr_readokres ();
extern bool_t xdr_readres ();
extern bool_t xdr_uint64 ();
extern bool_t xdr_int64 ();
extern bool_t xdr_uint32 ();
extern bool_t xdr_int32 ();
extern bool_t xdr_filename3 ();
extern bool_t xdr_nfspath3 ();
extern bool_t xdr_fileid3 ();
extern bool_t xdr_cookie3 ();
extern bool_t xdr_cookieverf3 ();
extern bool_t xdr_createverf3 ();
extern bool_t xdr_writeverf3 ();
extern bool_t xdr_uid3 ();
extern bool_t xdr_gid3 ();
extern bool_t xdr_size3 ();
extern bool_t xdr_offset3 ();
extern bool_t xdr_mode3 ();
extern bool_t xdr_count3 ();
extern bool_t xdr_nfsstat3 ();
extern bool_t xdr_ftype3 ();
extern bool_t xdr_specdata3 ();
extern bool_t xdr_nfs_fh3 ();
extern bool_t xdr_nfstime3 ();
extern bool_t xdr_fattr3 ();
extern bool_t xdr_post_op_attr ();
extern bool_t xdr_wcc_attr ();
extern bool_t xdr_pre_op_attr ();
extern bool_t xdr_wcc_data ();
extern bool_t xdr_diropargs3 ();
extern bool_t xdr_LOOKUP3args ();
extern bool_t xdr_LOOKUP3resok ();
extern bool_t xdr_LOOKUP3resfail ();
extern bool_t xdr_LOOKUP3res ();
extern bool_t xdr_READ3args ();
extern bool_t xdr_READ3resok ();
extern bool_t xdr_READ3resfail ();
extern bool_t xdr_READ3res ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NFS_PROT_H_RPCGEN */
