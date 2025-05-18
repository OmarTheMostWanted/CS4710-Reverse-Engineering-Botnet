typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long    undefined5;
typedef unsigned long    undefined6;
typedef unsigned long    undefined7;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef unsigned int    wchar32;
typedef struct termios termios, *Ptermios;

typedef uint tcflag_t;

typedef uchar cc_t;

typedef uint speed_t;

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;
};

typedef struct stat64 stat64, *Pstat64;

typedef ulong __dev_t;

typedef ulong __ino64_t;

typedef ulong __nlink_t;

typedef uint __mode_t;

typedef uint __uid_t;

typedef uint __gid_t;

typedef long __off_t;

typedef long __blksize_t;

typedef long __blkcnt64_t;

typedef struct timespec timespec, *Ptimespec;

typedef long __time_t;

struct timespec {
    __time_t tv_sec;
    long tv_nsec;
};

struct stat64 {
    __dev_t st_dev;
    __ino64_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};

typedef struct stat stat, *Pstat;

typedef ulong __ino_t;

typedef long __blkcnt_t;

struct stat {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};

typedef struct utsname utsname, *Putsname;

struct utsname {
    char sysname[65];
    char nodename[65];
    char release[65];
    char version[65];
    char machine[65];
    char domainname[65];
};

typedef int __int32_t;

typedef __int32_t *wctrans_t;

typedef union sem_t sem_t, *Psem_t;

union sem_t {
    char __size[32];
    long __align;
};

typedef struct __locale_data __locale_data, *P__locale_data;

struct __locale_data {
};

typedef struct __locale_struct __locale_struct, *P__locale_struct;

struct __locale_struct {
    struct __locale_data *__locales[13];
    ushort *__ctype_b;
    int *__ctype_tolower;
    int *__ctype_toupper;
    char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef ulong __fsfilcnt_t;

typedef int __pid_t;

typedef int __clockid_t;

typedef long __ssize_t;

typedef ulong __rlim_t;

typedef int int32_t;

typedef uint __useconds_t;

typedef long __suseconds_t;

typedef long __clock_t;

typedef __ssize_t ssize_t;

typedef long __off64_t;

typedef ulong __fsblkcnt_t;

typedef uint __socklen_t;

typedef struct __fsid_t __fsid_t, *P__fsid_t;

struct __fsid_t {
    int __val[2];
};

typedef struct pollfd pollfd, *Ppollfd;

struct pollfd {
    int fd;
    short events;
    short revents;
};

typedef ulong nfds_t;

typedef struct hostent hostent, *Phostent;

struct hostent {
    char *h_name;
    char **h_aliases;
    int h_addrtype;
    int h_length;
    char **h_addr_list;
};

typedef union pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;

typedef struct __pthread_mutex_s __pthread_mutex_s, *P__pthread_mutex_s;

typedef struct __pthread_internal_list __pthread_internal_list, *P__pthread_internal_list;

typedef struct __pthread_internal_list __pthread_list_t;

struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
};

struct __pthread_mutex_s {
    int __lock;
    uint __count;
    int __owner;
    uint __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
};

union pthread_mutex_t {
    struct __pthread_mutex_s __data;
    char __size[40];
    long __align;
};

typedef union pthread_mutexattr_t pthread_mutexattr_t, *Ppthread_mutexattr_t;

union pthread_mutexattr_t {
    char __size[4];
    int __align;
};

typedef union pthread_cond_t pthread_cond_t, *Ppthread_cond_t;

typedef struct _struct_16 _struct_16, *P_struct_16;

struct _struct_16 {
    int __lock;
    uint __futex;
    ulonglong __total_seq;
    ulonglong __wakeup_seq;
    ulonglong __woken_seq;
    void *__mutex;
    uint __nwaiters;
    uint __broadcast_seq;
};

union pthread_cond_t {
    struct _struct_16 __data;
    char __size[48];
    longlong __align;
};

typedef struct _struct_19 _struct_19, *P_struct_19;

struct _struct_19 {
    int __lock;
    uint __nr_readers;
    uint __readers_wakeup;
    uint __writer_wakeup;
    uint __nr_readers_queued;
    uint __nr_writers_queued;
    int __writer;
    int __shared;
    ulong __pad1;
    ulong __pad2;
    uint __flags;
};

typedef union pthread_rwlockattr_t pthread_rwlockattr_t, *Ppthread_rwlockattr_t;

union pthread_rwlockattr_t {
    char __size[8];
    long __align;
};

typedef union pthread_barrier_t pthread_barrier_t, *Ppthread_barrier_t;

union pthread_barrier_t {
    char __size[32];
    long __align;
};

typedef union pthread_rwlock_t pthread_rwlock_t, *Ppthread_rwlock_t;

union pthread_rwlock_t {
    struct _struct_19 __data;
    char __size[56];
    long __align;
};

typedef union pthread_condattr_t pthread_condattr_t, *Ppthread_condattr_t;

union pthread_condattr_t {
    char __size[4];
    int __align;
};

typedef ulong pthread_t;

typedef int pthread_spinlock_t;

typedef int pthread_once_t;

typedef uint pthread_key_t;

typedef union pthread_barrierattr_t pthread_barrierattr_t, *Ppthread_barrierattr_t;

union pthread_barrierattr_t {
    char __size[4];
    int __align;
};

typedef union pthread_attr_t pthread_attr_t, *Ppthread_attr_t;

union pthread_attr_t {
    char __size[56];
    long __align;
};

typedef struct dirent64 dirent64, *Pdirent64;

struct dirent64 {
    __ino64_t d_ino;
    __off64_t d_off;
    ushort d_reclen;
    uchar d_type;
    char d_name[256];
};

typedef struct __dirstream __dirstream, *P__dirstream;

typedef struct __dirstream DIR;

struct __dirstream {
};

typedef union sigval sigval, *Psigval;

union sigval {
    int sival_int;
    void *sival_ptr;
};

typedef struct siginfo siginfo, *Psiginfo;

typedef union _union_1441 _union_1441, *P_union_1441;

typedef struct _struct_1442 _struct_1442, *P_struct_1442;

typedef struct _struct_1443 _struct_1443, *P_struct_1443;

typedef struct _struct_1444 _struct_1444, *P_struct_1444;

typedef struct _struct_1445 _struct_1445, *P_struct_1445;

typedef struct _struct_1446 _struct_1446, *P_struct_1446;

typedef struct _struct_1447 _struct_1447, *P_struct_1447;

typedef union sigval sigval_t;

struct _struct_1445 {
    __pid_t si_pid;
    __uid_t si_uid;
    int si_status;
    __clock_t si_utime;
    __clock_t si_stime;
};

struct _struct_1444 {
    __pid_t si_pid;
    __uid_t si_uid;
    sigval_t si_sigval;
};

struct _struct_1443 {
    int si_tid;
    int si_overrun;
    sigval_t si_sigval;
};

struct _struct_1446 {
    void *si_addr;
};

struct _struct_1442 {
    __pid_t si_pid;
    __uid_t si_uid;
};

struct _struct_1447 {
    long si_band;
    int si_fd;
};

union _union_1441 {
    int _pad[28];
    struct _struct_1442 _kill;
    struct _struct_1443 _timer;
    struct _struct_1444 _rt;
    struct _struct_1445 _sigchld;
    struct _struct_1446 _sigfault;
    struct _struct_1447 _sigpoll;
};

struct siginfo {
    int si_signo;
    int si_errno;
    int si_code;
    union _union_1441 _sifields;
};

typedef struct siginfo siginfo_t;

typedef void *__gnuc_va_list;

typedef union _union_1457 _union_1457, *P_union_1457;

typedef void (*__sighandler_t)(int);

union _union_1457 {
    __sighandler_t sa_handler;
    void (*sa_sigaction)(int, siginfo_t *, void *);
};

typedef struct sigaction sigaction, *Psigaction;

typedef struct __sigset_t __sigset_t, *P__sigset_t;

struct __sigset_t {
    ulong __val[16];
};

struct sigaction {
    union _union_1457 __sigaction_handler;
    struct __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};

typedef struct __jmp_buf_tag __jmp_buf_tag, *P__jmp_buf_tag;

typedef long __jmp_buf[8];

struct __jmp_buf_tag {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    struct __sigset_t __saved_mask;
};

typedef struct __pthread_unwind_buf_t __pthread_unwind_buf_t, *P__pthread_unwind_buf_t;

typedef struct _struct_1387 _struct_1387, *P_struct_1387;

struct _struct_1387 {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
};

struct __pthread_unwind_buf_t {
    struct _struct_1387 __cancel_jmp_buf[1];
    void *__pad[4];
};

typedef ulong size_t;

typedef uint wint_t;

typedef ulong __cpu_mask;

typedef struct sched_param sched_param, *Psched_param;

struct sched_param {
    int __sched_priority;
};

typedef struct cpu_set_t cpu_set_t, *Pcpu_set_t;

struct cpu_set_t {
    __cpu_mask __bits[16];
};

typedef struct iovec iovec, *Piovec;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

typedef struct random_data random_data, *Prandom_data;

struct random_data {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
};

typedef int (*__compar_d_fn_t)(void *, void *, void *);

typedef int (*__compar_fn_t)(void *, void *);

typedef ushort sa_family_t;

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

typedef struct rlimit rlimit, *Prlimit;

typedef __rlim_t rlim_t;

struct rlimit {
    rlim_t rlim_cur;
    rlim_t rlim_max;
};

typedef enum __rlimit_resource {
    RLIMIT_CPU=0,
    RLIMIT_FSIZE=1,
    RLIMIT_DATA=2,
    RLIMIT_STACK=3,
    RLIMIT_CORE=4,
    __RLIMIT_RSS=5,
    __RLIMIT_NPROC=6,
    RLIMIT_NOFILE=7,
    __RLIMIT_MEMLOCK=8,
    __RLIMIT_OFILE=8,
    RLIMIT_AS=9,
    __RLIMIT_LOCKS=10,
    __RLIMIT_SIGPENDING=11,
    __RLIMIT_MSGQUEUE=12,
    __RLIMIT_NICE=13,
    __RLIMIT_RTPRIO=14,
    __RLIMIT_NLIMITS=15,
    __RLIM_NLIMITS=16
} __rlimit_resource;

typedef enum __rlimit_resource __rlimit_resource_t;

typedef struct statfs statfs, *Pstatfs;

struct statfs {
    long f_type;
    long f_bsize;
    __fsblkcnt_t f_blocks;
    __fsblkcnt_t f_bfree;
    __fsblkcnt_t f_bavail;
    __fsfilcnt_t f_files;
    __fsfilcnt_t f_ffree;
    struct __fsid_t f_fsid;
    long f_namelen;
    long f_frsize;
    long f_flags;
    long f_spare[4];
};

typedef struct _IO_FILE __FILE;

typedef struct _IO_FILE FILE;

typedef __socklen_t socklen_t;

typedef struct msghdr msghdr, *Pmsghdr;

struct msghdr {
    void *msg_name;
    socklen_t msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    int msg_flags;
};

typedef struct sockaddr sockaddr, *Psockaddr;

struct sockaddr {
    sa_family_t sa_family;
    char sa_data[14];
};

typedef void (*__free_fn_t)(void *);

typedef enum enum_1437 {
    preorder=0,
    postorder=1,
    endorder=2,
    leaf=3
} enum_1437;

typedef enum enum_1437 VISIT;

typedef void (*__action_fn_t)(void *, VISIT, int);

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

struct evp_pkey_ctx_st {
};

typedef struct __mbstate_t __mbstate_t, *P__mbstate_t;

typedef union _union_27 _union_27, *P_union_27;

union _union_27 {
    uint __wch;
    char __wchb[4];
};

struct __mbstate_t {
    int __count;
    union _union_27 __value;
};

typedef struct __mbstate_t mbstate_t;

typedef struct if_nameindex if_nameindex, *Pif_nameindex;

struct if_nameindex {
    uint if_index;
    char *if_name;
};

typedef struct timezone timezone, *Ptimezone;

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

typedef struct timeval timeval, *Ptimeval;

struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

typedef struct timezone *__timezone_ptr_t;

typedef enum __itimer_which {
    ITIMER_REAL=0,
    ITIMER_VIRTUAL=1,
    ITIMER_PROF=2
} __itimer_which;

typedef struct itimerval itimerval, *Pitimerval;

struct itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};

typedef __time_t time_t;

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long tm_gmtoff;
    char *tm_zone;
};

typedef enum __itimer_which __itimer_which_t;

typedef struct in_addr in_addr, *Pin_addr;

typedef uint uint32_t;

typedef uint32_t in_addr_t;

struct in_addr {
    in_addr_t s_addr;
};

typedef long __fd_mask;

typedef struct fd_set fd_set, *Pfd_set;

struct fd_set {
    __fd_mask fds_bits[16];
};

typedef struct __sigset_t sigset_t;

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    dword abiType; // 0 == Linux
    dword requiredKernelVersion[3]; // Major.minor.patch
};

typedef ushort uint16_t;

typedef long intptr_t;




void _init(void);
char * stpcpy(char *__dest,char *__src);
char * strcpy(char *__dest,char *__src);
size_t strnlen(char *__string,size_t __maxlen);
void * memmove(void *__dest,void *__src,size_t __n);
void * rawmemchr(void *__s,int __c);
int strncasecmp(char *__s1,char *__s2,size_t __n);
char * strncpy(char *__dest,char *__src,size_t __n);
int memcmp(void *__s1,void *__s2,size_t __n);
int strcasecmp_l(char *__s1,char *__s2,__locale_t __loc);
void * memset(void *__s,int __c,size_t __n);
int strcmp(char *__s1,char *__s2);
int strncasecmp_l(char *__s1,char *__s2,size_t __n,__locale_t __loc);
int strcasecmp(char *__s1,char *__s2);
char * strchr(char *__s,int __c);
void * memset(void *__s,int __c,size_t __n);
void * memmove(void *__dest,void *__src,size_t __n);
ulong __pthread_mutex_lock_full(uint *param_1);
undefined8 _L_unlock_288(void);
undefined1  [16] __pthread_mutex_unlock_full(uint *param_1,int param_2);
undefined1  [16] __pthread_once_slow(uint *param_1,code *param_2);
ulong __pthread_mutex_cond_lock_full(uint *param_1);
undefined8 _L_unlock_274(void);
void check_one_fd.part.0(int param_1,undefined8 param_2);
void munmap_chunk.part.1(long param_1);
void strip(undefined1 *param_1,char *param_2);
void read_int(long *param_1);
char * group_number(char *param_1,char *param_2,char *param_3,char *param_4);
void * _i18n_number_rewrite(void *param_1,long param_2,void *param_3);
void * _i18n_number_rewrite(void *param_1,long param_2,void *param_3);
void search_list_add__(long *param_1,long param_2);
undefined8 * nameserver_list_emplace__(long *param_1);
bool is_trusted_path_normalize(char *param_1,long param_2);
void read_int(undefined8 *param_1);
undefined4 * group_number(undefined4 *param_1,undefined4 *param_2,char *param_3,undefined4 param_4);
uint * _i18n_number_rewrite(uint *param_1,long param_2,uint *param_3);
void fini(void);
ulong init_cacheinfo(void);
void processEntry _start(undefined8 param_1,undefined8 param_2);
void deregister_tm_clones(void);
void register_tm_clones(void);
void __do_global_dtors_aux(void);
void frame_dummy(void);
void init_rand(int param_1);
undefined4 rand_cmwc(void);
uint getRandomIP(uint param_1);
long fdgets(long param_1,int param_2,int param_3);
int getOurIP(void);
void trim(char *param_1);
void printchar(long *param_1,undefined4 param_2);
int prints(undefined8 param_1,char *param_2,int param_3,uint param_4);
ulong printi(undefined8 param_1,uint param_2,ulong param_3,int param_4,int param_5,uint param_6,int param_7);
int print(undefined8 *param_1,byte *param_2,uint *param_3);
undefined4 sockprintf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,int param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
bool getHost(char *param_1,in_addr_t *param_2);
void makeRandomStr(long param_1,int param_2);
int recvLine(int param_1,char *param_2,int param_3);
undefined8 connectTimeout(int param_1,undefined8 param_2,uint16_t param_3,int param_4);
int listFork(void);
uint csum(ushort *param_1,int param_2);
undefined2 tcpcsum(long param_1,void *param_2);
void makeIPPacket(byte *param_1,undefined4 param_2,undefined4 param_3,byte param_4,short param_5);
void SendUDP(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
undefined8 ftcp(undefined8 param_1,int param_2,int param_3,int param_4,char *param_5,int param_6,int param_7);
void SendSTDHEX(char *param_1,undefined2 param_2,int param_3);
int socket_connect(char *param_1,uint16_t param_2);
void makevsepacket(byte *param_1,undefined4 param_2,undefined4 param_3,byte param_4,short param_5);
void vseattack(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,int param_8);
void SendSTD(char *param_1,undefined2 param_2,int param_3);
void stdhexflood(char *param_1,undefined2 param_2,int param_3);
void SendSTD_HEX(char *param_1,undefined2 param_2,int param_3);
undefined8 rtcp(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
void audp(undefined8 param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
undefined8 atcp(undefined8 param_1,int param_2,int param_3,int param_4,char *param_5,int param_6,int param_7);
void astd(char *param_1,undefined2 param_2,int param_3,int param_4);
char * getArch(void);
char * getPortz(void);
void processCmd(int param_count,undefined8 *params);
bool initConnection(void);
void main(void);
void sigcancel_handler(int param_1,long param_2);
undefined1  [16] sighandler_setxid(int param_1,long param_2,ulong param_3);
undefined8 __nptl_set_robust(void);
void __pthread_initialize_minimal_internal(undefined8 param_1,undefined8 param_2,undefined8 param_3);
long __pthread_get_minstack(void);
void __nptl_create_event(void);
void __nptl_death_event(void);
undefined1  [16] setxid_mark_thread.isra.1(long param_1,undefined8 param_2,ulong param_3);
void __free_stacks(ulong param_1);
void __deallocate_stack(long param_1);
int do_clone.constprop.4(void *param_1,long param_2,void *param_3,int param_4);
int __make_stacks_executable(void);
void __reclaim_stacks(void);
undefined ** __find_thread_by_id(int param_1);
ulong __nptl_setxid(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void __pthread_init_static_tls(long param_1);
ulong __wait_lookup_done(void);
undefined ** __find_in_stack_list(undefined **param_1);
void __nptl_deallocate_tsd(void);
undefined8 start_thread(long param_1);
void __free_tcb(long param_1);
int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,void *__arg);
void _L_lock_234(void);
void _L_unlock_321(void);
int _L_lock_458(void);
int _L_lock_636(void);
undefined4 _L_unlock_717(void);
undefined ** _L_lock_1271(void);
undefined8 _L_unlock_1320(void);
ulong _L_lock_1404(void);
undefined4 _L_unlock_1941(undefined8 param_1,undefined4 param_2);
void _L_lock_2020(void);
void _L_unlock_2126(void);
ulong _L_lock_2158(void);
void _L_unlock_2332(void);
undefined ** _L_lock_2356(void);
undefined8 _L_unlock_2405(undefined8 param_1,undefined8 param_2);
undefined8 _L_lock_2994(void);
undefined8 _L_unlock_3001(void);
int _L_lock_3386(void);
int _L_unlock_3522(void);
undefined8 _L_unlock_3820(void);
undefined8 _L_unlock_4275(void);
int _L_lock_4370(void);
int _L_unlock_4393(void);
int _L_unlock_4475(void);
int _L_lock_4541(void);
int _L_unlock_4572(void);
int _L_lock_4861(void);
int _L_unlock_4884(void);
void pthread_exit(void *__retval);
int pthread_detach(pthread_t __th);
void cleanup(EVP_PKEY_CTX *ctx);
int pthread_join(pthread_t __th,void **__thread_return);
int pthread_tryjoin_np(pthread_t __th,void **__thread_return);
void cleanup(EVP_PKEY_CTX *ctx);
int pthread_timedjoin_np(pthread_t __th,void **__thread_return,timespec *__abstime);
pthread_t pthread_self(void);
int pthread_equal(pthread_t __thread1,pthread_t __thread2);
int pthread_yield(void);
int pthread_getconcurrency(void);
int pthread_setconcurrency(int __level);
int pthread_getschedparam(pthread_t __target_thread,int *__policy,sched_param *__param);
undefined4 _L_lock_36(void);
undefined4 _L_unlock_69(void);
int pthread_setschedparam(pthread_t __target_thread,int __policy,sched_param *__param);
ulong _L_lock_32(void);
undefined4 _L_unlock_67(void);
int pthread_setschedprio(pthread_t __target_thread,int __prio);
ulong _L_lock_28(void);
undefined4 _L_unlock_59(void);
int pthread_attr_init(pthread_attr_t *__attr);
int pthread_attr_destroy(pthread_attr_t *__attr);
int pthread_attr_getdetachstate(pthread_attr_t *__attr,int *__detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *__attr,int __detachstate);
int pthread_attr_getguardsize(pthread_attr_t *__attr,size_t *__guardsize);
int pthread_attr_setguardsize(pthread_attr_t *__attr,size_t __guardsize);
int pthread_attr_getschedparam(pthread_attr_t *__attr,sched_param *__param);
int pthread_attr_setschedparam(pthread_attr_t *__attr,sched_param *__param);
int pthread_attr_getschedpolicy(pthread_attr_t *__attr,int *__policy);
int pthread_attr_setschedpolicy(pthread_attr_t *__attr,int __policy);
int pthread_attr_getinheritsched(pthread_attr_t *__attr,int *__inherit);
int pthread_attr_setinheritsched(pthread_attr_t *__attr,int __inherit);
int pthread_attr_getscope(pthread_attr_t *__attr,int *__scope);
int pthread_attr_setscope(pthread_attr_t *__attr,int __scope);
int pthread_attr_getstackaddr(pthread_attr_t *__attr,void **__stackaddr);
int pthread_attr_setstackaddr(pthread_attr_t *__attr,void *__stackaddr);
int pthread_attr_getstacksize(pthread_attr_t *__attr,size_t *__stacksize);
int pthread_attr_setstacksize(pthread_attr_t *__attr,size_t __stacksize);
int pthread_attr_getstack(pthread_attr_t *__attr,void **__stackaddr,size_t *__stacksize);
int pthread_attr_setstack(pthread_attr_t *__attr,void *__stackaddr,size_t __stacksize);
int pthread_getattr_np(pthread_t __th,pthread_attr_t *__attr);
int _L_lock_37(void);
undefined4 _L_unlock_155(void);
int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr);
int pthread_mutex_destroy(pthread_mutex_t *__mutex);
int pthread_mutex_lock(pthread_mutex_t *__mutex);
undefined8 _L_lock_883(void);
undefined8 _L_lock_941(void);
undefined1  [16] _L_lock_1093(void);
int pthread_mutex_trylock(pthread_mutex_t *__mutex);
undefined8 _L_unlock_813(void);
int pthread_mutex_timedlock(pthread_mutex_t *__mutex,timespec *__abstime);
undefined8 _L_timedlock_463(void);
undefined8 _L_timedlock_518(void);
undefined8 _L_timedlock_594(void);
undefined8 _L_unlock_1188(void);
ulong __pthread_mutex_unlock_usercnt(int *param_1,int param_2);
int pthread_mutex_unlock(pthread_mutex_t *__mutex);
undefined4 _L_unlock_594(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5);
undefined4 _L_unlock_738(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5);
int pthread_mutexattr_init(pthread_mutexattr_t *__attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr);
int pthread_mutexattr_getpshared(pthread_mutexattr_t *__attr,int *__pshared);
int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr,int __pshared);
int pthread_mutexattr_getkind_np(pthread_mutexattr_t *__attr,int *__kind);
int pthread_mutexattr_settype(pthread_mutexattr_t *__attr,int __kind);
int pthread_rwlock_init(pthread_rwlock_t *__rwlock,pthread_rwlockattr_t *__attr);
int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock);
int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock);
int pthread_rwlock_timedrdlock(pthread_rwlock_t *__rwlock,timespec *__abstime);
int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock);
int pthread_rwlock_timedwrlock(pthread_rwlock_t *__rwlock,timespec *__abstime);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *__rwlock);
ulong _L_lock_14(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_unlock_32(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5);
int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock);
ulong _L_lock_14(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_unlock_32(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5);
int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock);
int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr);
int pthread_rwlockattr_getpshared(pthread_rwlockattr_t *__attr,int *__pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr,int __pshared);
int pthread_rwlockattr_getkind_np(pthread_rwlockattr_t *__attr,int *__pref);
int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *__attr,int __pref);
int pthread_cond_init(pthread_cond_t *__cond,pthread_condattr_t *__cond_attr);
int pthread_cond_destroy(pthread_cond_t *__cond);
undefined8 _L_lock_39(void);
undefined8 _L_unlock_50(void);
undefined8 _L_unlock_119(undefined8 param_1,ulong param_2,ulong param_3,undefined8 param_4,int *param_5,uint param_6);
undefined8 _L_lock_135(undefined8 param_1,ulong param_2,ulong param_3,undefined8 param_4,int *param_5,uint param_6);
int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex);
void __condvar_cleanup1(void);
int pthread_cond_timedwait(pthread_cond_t *__cond,pthread_mutex_t *__mutex,timespec *__abstime);
void __condvar_cleanup2(void);
int pthread_cond_signal(pthread_cond_t *__cond);
int pthread_cond_broadcast(pthread_cond_t *__cond);
int pthread_condattr_init(pthread_condattr_t *__attr);
int pthread_condattr_destroy(pthread_condattr_t *__attr);
int pthread_condattr_getpshared(pthread_condattr_t *__attr,int *__pshared);
int pthread_condattr_setpshared(pthread_condattr_t *__attr,int __pshared);
int pthread_condattr_getclock(pthread_condattr_t *__attr,__clockid_t *__clock_id);
int pthread_condattr_setclock(pthread_condattr_t *__attr,__clockid_t __clock_id);
int pthread_spin_destroy(pthread_spinlock_t *__lock);
int pthread_spin_lock(pthread_spinlock_t *__lock);
int pthread_spin_trylock(pthread_spinlock_t *__lock);
int pthread_spin_init(pthread_spinlock_t *__lock,int __pshared);
int pthread_barrier_init(pthread_barrier_t *__barrier,pthread_barrierattr_t *__attr,uint __count);
int pthread_barrier_destroy(pthread_barrier_t *__barrier);
undefined8 _L_lock_19(undefined8 param_1,undefined8 param_2,long param_3);
undefined8 _L_unlock_39(undefined8 param_1,undefined8 param_2,long param_3);
int pthread_barrier_wait(pthread_barrier_t *__barrier);
int pthread_barrierattr_init(pthread_barrierattr_t *__attr);
int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr);
int pthread_barrierattr_getpshared(pthread_barrierattr_t *__attr,int *__pshared);
int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr,int __pshared);
int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function);
int pthread_key_delete(pthread_key_t __key);
void * pthread_getspecific(pthread_key_t __key);
int pthread_setspecific(pthread_key_t __key,void *__pointer);
int pthread_sigmask(int __how,__sigset_t *__newmask,__sigset_t *__oldmask);
int pthread_kill(pthread_t __threadid,int __signo);
int pthread_sigqueue(pthread_t __threadid,int __signo,sigval __value);
int pthread_cancel(pthread_t __th);
void pthread_testcancel(void);
int pthread_setcancelstate(int __state,int *__oldstate);
int pthread_setcanceltype(int __type,int *__oldtype);
undefined1  [16] clear_once_control(undefined4 *param_1);
int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine);
int pthread_atfork(__prepare *__prepare,__parent *__parent,__child *__child);
int pthread_getcpuclockid(pthread_t __thread_id,__clockid_t *__clock_id);
undefined8 __pthread_clock_gettime(uint param_1,ulong param_2,ulong *param_3);
undefined8 __pthread_clock_settime(uint param_1,undefined8 param_2);
int sem_init(sem_t *__sem,int __pshared,uint __value);
int sem_destroy(sem_t *__sem);
void __where_is_shmfs(void);
void * check_add_mapping(void *param_1,size_t param_2,int param_3,void *param_4);
uint __sem_search(ulong *param_1,ulong *param_2);
sem_t * sem_open(char *__name,int __oflag,...);
void * _L_lock_269(void);
undefined8 _L_unlock_346(void);
void walker(long *param_1);
int sem_close(sem_t *__sem);
int _L_lock_36(void);
undefined4 _L_unlock_65(void);
int sem_unlink(char *__name);
int sem_getvalue(sem_t *__sem,int *__sval);
void __sem_wait_cleanup(long *param_1);
void do_futex_wait.constprop.1(long param_1);
undefined8 __new_sem_wait_slow.constprop.0(long *param_1);
int sem_wait(sem_t *__sem);
int sem_trywait(sem_t *__sem);
void __sem_wait_cleanup(long *param_1);
int do_futex_wait(long param_1,long *param_2,undefined8 param_3,undefined8 param_4);
undefined8 __new_sem_wait_slow(long *param_1,undefined8 param_2);
int sem_timedwait(sem_t *__sem,timespec *__abstime);
int sem_post(sem_t *__sem);
void __pthread_register_cancel(__pthread_unwind_buf_t *__buf);
void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf);
void __pthread_register_cancel_defer(__pthread_unwind_buf_t *__buf);
void __pthread_unregister_cancel_restore(__pthread_unwind_buf_t *__buf);
void _pthread_cleanup_push(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
void _pthread_cleanup_pop(undefined8 *param_1,int param_2);
void _pthread_cleanup_push_defer(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
void __pthread_cleanup_pop_restore(undefined8 *param_1,int param_2);
void unwind_cleanup(void);
undefined8 unwind_stop(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,__jmp_buf_tag *param_6);
void __pthread_unwind(undefined8 param_1);
void __pthread_unwind_next(__pthread_unwind_buf_t *__buf);
void siglongjmp(__jmp_buf_tag *__env,int __val);
void __pthread_cleanup_upto(long param_1,long param_2);
void __pthread_enable_asynccancel(void);
void __pthread_disable_asynccancel(ulong param_1);
void __lll_lock_wait_private(int *param_1);
void __lll_lock_wait(int *param_1);
int __lll_timedlock_wait(int *param_1,undefined8 param_2,long *param_3);
undefined1  [16]__lll_unlock_wake_private(undefined4 *param_1,undefined8 param_2,undefined8 param_3);
undefined1  [16] __lll_unlock_wake(undefined4 *param_1,undefined8 param_2,undefined8 param_3);
undefined1  [16] __lll_timedwait_tid(uint *param_1,long *param_2);
__pid_t vfork(void);
ssize_t write(int __fd,void *__buf,size_t __n);
undefined8 __write_nocancel(void);
ssize_t read(int __fd,void *__buf,size_t __nbytes);
undefined8 __read_nocancel(void);
int close(int __fd);
undefined8 __close_nocancel(void);
int __fcntl_nocancel(undefined8 param_1,int param_2);
int fcntl(int __fd,int __cmd,...);
int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len);
undefined8 __accept_nocancel(void);
int connect(int __fd,sockaddr *__addr,socklen_t __len);
undefined8 __connect_nocancel(void);
ssize_t recv(int __fd,void *__buf,size_t __n,int __flags);
ssize_t recvfrom(int __fd,void *__buf,size_t __n,int __flags,sockaddr *__addr,socklen_t *__addr_len);
undefined8 __recvfrom_nocancel(void);
ssize_t recvmsg(int __fd,msghdr *__message,int __flags);
undefined8 __recvmsg_nocancel(void);
ssize_t send(int __fd,void *__buf,size_t __n,int __flags);
ssize_t sendmsg(int __fd,msghdr *__message,int __flags);
undefined8 __sendmsg_nocancel(void);
ssize_t sendto(int __fd,void *__buf,size_t __n,int __flags,sockaddr *__addr,socklen_t __addr_len);
undefined8 __sendto_nocancel(void);
int fsync(int __fd);
undefined8 __fsync_nocancel(void);
__off64_t lseek64(int __fd,__off64_t __offset,int __whence);
undefined8 __lseek_nocancel(void);
int msync(void *__addr,size_t __len,int __flags);
undefined8 __msync_nocancel(void);
int nanosleep(timespec *__requested_time,timespec *__remaining);
undefined8 __nanosleep_nocancel(void);
int open(char *__file,int __oflag,...);
undefined8 __open_nocancel(void);
int pause(void);
undefined8 __pause_nocancel(void);
ssize_t pread(int __fd,void *__buf,size_t __nbytes,__off64_t __offset);
undefined8 __pread_nocancel(void);
ssize_t pwrite(int __fd,void *__buf,size_t __n,__off64_t __offset);
undefined8 __pwrite_nocancel(void);
int tcdrain(int __fd);
__pid_t wait(void *__stat_loc);
__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options);
ssize_t msgrcv(int __msqid,void *__msgp,size_t __msgsz,long __msgtyp,int __msgflg);
undefined8 __msgrcv_nocancel(void);
int msgsnd(int __msqid,void *__msgp,size_t __msgsz,int __msgflg);
undefined8 __msgsnd_nocancel(void);
int sigwait(sigset_t *__set,int *__sig);
int sigsuspend(sigset_t *__set);
undefined8 __sigsuspend_nocancel(void);
int raise(int __sig);
ulong system(long param_1);
void flockfile(FILE *__stream);
void _L_lock_22(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,long param_5,undefined8 param_6);
int ftrylockfile(FILE *__stream);
void funlockfile(FILE *__stream);
void _L_unlock_13(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_004100ef(undefined1 *param_1,undefined8 param_2,undefined8 *param_3,char param_4);
undefined __restore_rt();
undefined8 __libc_sigaction(undefined8 param_1,undefined8 param_2,undefined8 *param_3);
int sigaction(int __sig,sigaction *__act,sigaction *__oact);
int * __h_errno_location(void);
undefined8 __res_state(void);
int pthread_getaffinity_np(pthread_t __th,size_t __cpusetsize,cpu_set_t *__cpuset);
undefined8 __determine_cpumask_size(void);
int pthread_setaffinity_np(pthread_t __th,size_t __cpusetsize,cpu_set_t *__cpuset);
int pthread_attr_getaffinity_np(pthread_attr_t *__attr,size_t __cpusetsize,cpu_set_t *__cpuset);
int pthread_attr_setaffinity_np(pthread_attr_t *__attr,size_t __cpusetsize,cpu_set_t *__cpuset);
int pthread_mutexattr_getrobust_np(pthread_mutexattr_t *__attr,int *__robustness);
int pthread_mutexattr_setrobust(pthread_mutexattr_t *__attr,int __robustness);
int pthread_mutex_consistent_np(pthread_mutex_t *__mutex);
void __pthread_cleanup_routine(undefined8 *param_1);
int pthread_mutexattr_getprotocol(pthread_mutexattr_t *__attr,int *__protocol);
int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__attr,int __protocol);
int pthread_mutexattr_getprioceiling(pthread_mutexattr_t *__attr,int *__prioceiling);
int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *__attr,int __prioceiling);
void __init_sched_fifo_prio(void);
int __pthread_tpp_change_priority(int param_1,int param_2);
ulong __pthread_current_priority(void);
int _L_lock_125(void);
undefined4 _L_unlock_187(void);
ulong _L_lock_526(void);
undefined4 _L_unlock_559(void);
int pthread_mutex_getprioceiling(pthread_mutex_t *__mutex,int *__prioceiling);
int pthread_mutex_setprioceiling(pthread_mutex_t *__mutex,int __prioceiling,int *__old_ceiling);
int pthread_setname_np(pthread_t __target_thread,char *__name);
int pthread_getname_np(pthread_t __target_thread,char *__buf,size_t __buflen);
void elision_init(void);
undefined8 __lll_lock_elision(int *param_1,short *param_2,undefined4 param_3);
undefined8 _L_lock_58(void);
undefined8 __lll_unlock_elision(int *param_1);
undefined8 _L_unlock_13(undefined8 param_1,undefined8 param_2,undefined8 param_3);
ulong __lll_timedlock_elision(uint *param_1,short *param_2,undefined8 param_3,undefined4 param_4);
void _L_timedlock_34(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
int __lll_trylock_elision(int *param_1,short *param_2);
undefined8 fork(void);
undefined8 __pthread_mutex_cond_lock(int *param_1);
void __pthread_mutex_cond_lock_adjust(long param_1);
undefined8 _L_cond_lock_847(void);
undefined8 _L_cond_lock_898(void);
undefined8 _L_cond_lock_938(void);
undefined1  [16] _L_cond_lock_1074(void);
int * __errno_location(void);
void generic_start_main(code *param_1,int param_2,long param_3,code *param_4,long param_5,long param_6,undefined8 param_7);
void __libc_start_main(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7);
undefined8 __syscall_error(void);
void __libc_check_standard_fds(void);
void __libc_setup_tls(long param_1,ulong param_2);
undefined8 _dl_tls_setup(void);
void FUN_00412010(void);
void __libc_csu_init(undefined4 param_1,undefined8 param_2,undefined8 param_3);
void __libc_csu_fini(void);
int isalnum(int param_1);
int isalpha(int param_1);
int iscntrl(int param_1);
int isdigit(int param_1);
int islower(int param_1);
int isgraph(int param_1);
int isprint(int param_1);
int ispunct(int param_1);
int isspace(int param_1);
int isupper(int param_1);
int isxdigit(int param_1);
int tolower(int __c);
int toupper(int __c);
ushort ** __ctype_b_loc(void);
__int32_t ** __ctype_toupper_loc(void);
__int32_t ** __ctype_tolower_loc(void);
void __ctype_init(void);
int _setjmp(__jmp_buf_tag *__env);
void __libc_siglongjmp(__jmp_buf_tag *__env,int __val);
void __longjmp(long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4);
void _longjmp_unwind(void);
__sighandler_t signal(int __sig,__sighandler_t __handler);
int sigprocmask(int __how,sigset_t *__set,sigset_t *__oset);
int kill(__pid_t __pid,int __sig);
int atoi(char *__nptr);
void abort(void);
void _L_lock_26(void);
void _L_unlock_138(void);
void _L_lock_159(void);
char * secure_getenv(char *param_1);
void __run_exit_handlers(int param_1,long *param_2,char param_3);
void exit(int __status);
long * __new_exitfn(undefined8 *param_1);
undefined8 __internal_atexit(ulong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 __cxa_atexit(ulong param_1,undefined8 param_2,undefined8 param_3);
long * _L_lock_23(void);
undefined8 _L_unlock_135(undefined8 param_1,undefined8 param_2);
void srandom(uint __seed);
char * initstate(uint __seed,char *__statebuf,size_t __statelen);
char * setstate(char *__statebuf);
long random(void);
void _L_lock_12(void);
void _L_unlock_24(void);
long _L_lock_48(void);
long _L_unlock_65(void);
long _L_lock_89(void);
void _L_unlock_109(void);
long _L_lock_131(void);
long _L_unlock_141(void);
int srandom_r(uint __seed,random_data *__buf);
int initstate_r(uint __seed,char *__statebuf,size_t __statelen,random_data *__buf);
int setstate_r(char *__statebuf,random_data *__buf);
int random_r(random_data *__buf,int32_t *__result);
int rand(void);
void __strtoll_internal(void);
longlong strtol(char *__nptr,char **__endptr,int __base);
void __strtoul_internal(void);
ulonglong strtouq(char *__nptr,char **__endptr,int __base);
ulong ____strtoll_l_internal(byte *param_1,undefined8 *param_2,uint param_3,int param_4,long param_5);
long strtol_l(char *__nptr,char **__endptr,int __base,__locale_t __loc);
ulong ____strtoull_l_internal(byte *param_1,undefined8 *param_2,uint param_3,int param_4,long param_5);
ulong strtoul_l(char *__nptr,char **__endptr,int __base,__locale_t __loc);
int cancel_handler(__pid_t *param_1);
undefined4 do_system(void);
ulong __libc_system(long param_1);
void _L_lock_55(void);
void _L_unlock_76(void);
undefined4 _L_lock_113(void);
int _L_unlock_143(void);
undefined4 _L_lock_264(void);
undefined4 _L_unlock_292(void);
undefined8 _L_unlock_372(void);
undefined8 _L_lock_412(void);
ulong __correctly_grouped_prefixmb(ulong param_1,ulong param_2,char *param_3,char *param_4);
int sprintf(char *__s,char *__format,...);
int sscanf(char *__s,char *__format,...);
int fclose(FILE *__stream);
int _L_lock_43(void);
undefined4 _L_lock_137(void);
undefined4 _L_unlock_150(void);
undefined4 _L_unlock_254(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void _L_unlock_315(undefined8 param_1,undefined8 param_2,undefined8 param_3);
byte * __fopen_maybe_mmap(byte *param_1);
byte * __fopen_internal(undefined8 param_1,undefined8 param_2,undefined4 param_3);
FILE * fopen64(char *__filename,char *__modes);
__ssize_t getdelim(char **__lineptr,size_t *__n,int __delimiter,FILE *__stream);
long _L_lock_67(void);
void _L_unlock_273(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void _L_unlock_430(undefined8 param_1,undefined8 param_2,undefined8 param_3);
int vsprintf(char *__s,char *__format,__gnuc_va_list __arg);
int vsscanf(char *__s,char *__format,__gnuc_va_list __arg);
undefined4 _IO_wfile_underflow(uint *param_1);
undefined4 _IO_wfile_underflow_mmap(uint *param_1);
void _IO_wfile_underflow_maybe_mmap(long param_1);
ulong _IO_wfile_seekoff(uint *param_1,ulong param_2,int param_3,int param_4);
ulong _IO_wdo_write(uint *param_1,long param_2,long param_3);
ulong _IO_wfile_overflow(uint *param_1,uint param_2);
undefined8 _IO_wfile_sync(long param_1);
long _IO_wfile_xsputn(uint *param_1,wchar_t *param_2,ulong param_3);
undefined4 _L_lock_90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
undefined4 _L_unlock_555(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void _L_unlock_920(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 fcloseall(void);
void __libc_message.constprop.0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
void __libc_message(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,int param_9,char *param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
void __libc_fatal(undefined8 param_1);
void _IO_vtable_check(void);
long _IO_file_seekoff_maybe_mmap(long param_1,undefined8 param_2,ulong param_3);
void _IO_file_close(long param_1);
long _IO_new_file_setbuf(long param_1);
ulong _IO_new_file_underflow(uint *param_1);
ulong _IO_new_file_seekoff(uint *param_1,ulong param_2,int param_3,int param_4);
void _IO_file_close_mmap(long param_1);
void _IO_file_seek(long param_1,__off64_t param_2,int param_3);
undefined8 _IO_file_sync_mmap(uint *param_1);
void _IO_file_xsgetn_maybe_mmap(long param_1,undefined8 param_2,undefined8 param_3);
void _IO_file_stat(long param_1,stat *param_2);
void _IO_new_file_write(uint *param_1,void *param_2,size_t param_3);
long _IO_file_xsgetn_mmap(uint *param_1,void *param_2,ulong param_3);
long _IO_file_xsgetn(_IO_FILE *param_1,void *param_2,ulong param_3);
long _IO_file_seekoff_mmap(uint *param_1,long param_2,int param_3,int param_4);
ssize_t _IO_file_read(long param_1,void *param_2,size_t param_3);
long _IO_file_xsputn(uint *param_1,char *param_2,char *param_3);
long _IO_file_setbuf_mmap(long param_1);
void _IO_file_underflow_maybe_mmap(long param_1);
ulong _IO_file_underflow_mmap(uint *param_1);
void _IO_new_file_init_internal(uint *param_1);
void _IO_file_init(uint *param_1);
uint * _IO_file_open(uint *param_1,char *param_2,int param_3,undefined4 param_4,uint param_5);
uint * _IO_file_attach(uint *param_1,uint param_2);
int _IO_do_write(uint *param_1,undefined8 param_2,ulong param_3);
uint _IO_file_close_it(uint *param_1);
uint * _IO_file_fopen(uint *param_1,char *param_2,char *param_3);
void _IO_new_file_finish(byte *param_1);
ulong _IO_new_file_overflow(_IO_FILE *param_1,ulong param_2);
undefined8 _IO_new_file_sync(long param_1);
ulong _L_lock_220(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
ulong _L_unlock_426(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void _L_unlock_622(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void flush_cleanup(void);
undefined8 save_for_backup(long param_1,long param_2);
undefined8 _IO_cleanup(void);
void _IO_un_link(uint *param_1);
void _IO_link_in(uint *param_1);
void _IO_least_marker(long param_1,long param_2);
void _IO_switch_to_main_get_area(uint *param_1);
void _IO_switch_to_backup_area(uint *param_1);
undefined8 _IO_switch_to_get_mode(uint *param_1);
void _IO_free_backup_area(_IO_FILE *param_1);
int __overflow(_IO_FILE *param_1,int param_2);
int __underflow(_IO_FILE *param_1);
int __uflow(_IO_FILE *param_1);
void _IO_setb(uint *param_1,undefined8 param_2,undefined8 param_3,int param_4);
void _IO_doallocbuf(uint *param_1);
undefined8 _IO_default_underflow(void);
ulong _IO_default_uflow(long param_1);
long _IO_default_xsputn(long param_1,undefined8 *param_2,ulong param_3);
size_t _IO_sgetn(_IO_FILE *param_1,void *param_2,size_t param_3);
long _IO_default_xsgetn(uint *param_1,undefined8 *param_2,ulong param_3);
uint * _IO_default_setbuf(uint *param_1,long param_2,long param_3);
void _IO_default_seekpos(long param_1,undefined8 param_2,undefined4 param_3);
undefined1 * _IO_default_doallocate(uint *param_1);
void _IO_init_internal(uint *param_1,uint param_2);
void _IO_init(uint *param_1,uint param_2);
void _IO_old_init(uint *param_1,uint param_2);
void _IO_no_init(uint *param_1,uint param_2,uint param_3,undefined8 *param_4,undefined8 param_5);
undefined8 _IO_default_sync(void);
void _IO_default_finish(byte *param_1);
undefined8 _IO_default_seekoff(void);
ulong _IO_sputbackc(uint *param_1,ulong param_2);
ulong _IO_sungetc(uint *param_1);
int _IO_adjust_column(int param_1,char *param_2,int param_3);
undefined4 _IO_flush_all_lockp(int param_1);
void _IO_flush_all(void);
void _flushlbf(void);
void _IO_init_marker(undefined8 *param_1,uint *param_2);
void _IO_remove_marker(long *param_1);
int _IO_marker_difference(long param_1,long param_2);
int _IO_marker_delta(long param_1);
undefined8 _IO_seekmark(uint *param_1,long param_2);
void _IO_unsave_markers(uint *param_1);
uint _IO_default_pbackfail(uint *param_1,uint param_2);
undefined8 _IO_default_seek(void);
undefined8 _IO_default_stat(void);
undefined8 _IO_default_read(void);
undefined8 _IO_default_write(void);
undefined8 _IO_default_showmanyc(void);
void _IO_default_imbue(void);
undefined * _IO_iter_begin(void);
undefined8 _IO_iter_end(void);
undefined8 _IO_iter_next(long param_1);
undefined8 _IO_iter_file(undefined8 param_1);
void _IO_list_lock(void);
void _IO_list_unlock(void);
void _IO_list_resetlock(void);
void _L_unlock_22(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void _L_unlock_35(void);
undefined4 _L_unlock_837(undefined8 param_1,undefined8 param_2,int *param_3);
void _L_lock_970(void);
void _L_lock_1011(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
void _L_unlock_1087(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void _L_unlock_1136(void);
void _L_lock_1240(void);
void _L_unlock_1288(void);
void _L_lock_1340(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
void _L_unlock_1379(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_lock_4993(void);
undefined4 _L_lock_5091(undefined8 param_1,undefined8 param_2,int *param_3);
undefined4 _L_unlock_5176(undefined8 param_1,undefined8 param_2,int *param_3);
undefined4 _L_unlock_5268(void);
void _L_lock_5376(void);
void _L_unlock_5445(undefined8 param_1,undefined8 param_2,int *param_3);
void _L_lock_5491(undefined8 param_1,undefined8 param_2,int *param_3);
void _L_unlock_5575(void);
void _L_lock_6415(void);
void _L_unlock_6444(void);
ulong _IO_str_underflow(uint *param_1);
int _IO_str_overflow(uint *param_1,int param_2);
undefined8 _IO_str_pbackfail(byte *param_1,int param_2);
void _IO_str_finish(byte *param_1);
long _IO_str_seekoff(uint *param_1,long param_2,int param_3,uint param_4);
void _IO_str_init_static_internal(long param_1,void *param_2,long param_3,long param_4);
void _IO_str_init_static(long param_1,void *param_2,int param_3,long param_4);
void _IO_str_init_readonly(uint *param_1,void *param_2,int param_3);
long _IO_str_count(long param_1);
ulong mem2chunk_check(ulong param_1,long *param_2);
void * new_heap(ulong param_1,long param_2);
void malloc_printerr(uint param_1,undefined8 param_2,undefined8 param_3,long param_4);
undefined8 systrim.isra.2(long param_1,long *param_2,long *param_3);
int * arena_get2.isra.3(long param_1,int *param_2);
undefined4 * arena_get_retry(int *param_1,undefined8 param_2);
undefined8 top_check(void);
void malloc_consolidate(int *param_1);
void int_mallinfo(undefined4 *param_1,int *param_2);
undefined8 heap_trim(undefined8 *param_1,ulong param_2);
long * _int_free(uint *param_1,long *param_2,int param_3);
void free_atfork(long param_1);
undefined8 * sysmalloc(ulong param_1,undefined4 *param_2);
int * _int_malloc(int *param_1,ulong param_2);
long malloc_check(ulong param_1);
long * _int_memalign(undefined4 *param_1,ulong param_2,ulong param_3);
long memalign_check(ulong param_1,ulong param_2);
void free_check(long param_1);
long * _int_realloc(int *param_1,long *param_2,ulong param_3,ulong param_4);
long * realloc_check(long *param_1,ulong param_2);
void __malloc_fork_lock_parent(void);
void __malloc_fork_unlock_parent(void);
void __malloc_fork_unlock_child(void);
void __malloc_check_init(void);
void * malloc(size_t __size);
void * malloc_atfork(size_t param_1);
undefined8 * malloc_get_state(void);
void free(void *__ptr);
void * realloc(void *__ptr,size_t __size);
void * aligned_alloc(ulong param_1,ulong param_2);
void * calloc(size_t __nmemb,size_t __size);
ulong malloc_usable_size(long param_1);
ulong mallopt(undefined4 param_1,uint param_2);
void ptmalloc_init.part.7(void);
void malloc_hook_ini(size_t param_1);
void * realloc_hook_ini(void *param_1,ulong param_2);
void memalign_hook_ini(undefined8 param_1,undefined8 param_2);
undefined8 malloc_set_state(long *param_1);
void * valloc(size_t __size);
long pvalloc(ulong param_1);
uint malloc_trim(undefined8 param_1);
undefined8 * mallinfo(undefined8 *param_1);
void malloc_stats(void);
int posix_memalign(void **__memptr,size_t __alignment,size_t __size);
undefined8 malloc_info(int param_1,FILE *param_2);
int * _L_lock_1073(void);
int * _L_unlock_1104(void);
undefined8 _L_lock_1115(undefined8 param_1,undefined8 param_2,undefined8 param_3);
long _L_lock_1322(void);
long _L_lock_1348(void);
long _L_unlock_1414(void);
int * _L_lock_1727(void);
int * _L_unlock_1737(void);
int * _L_lock_1743(void);
int * _L_unlock_1762(void);
long _L_lock_1768(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 * _L_unlock_1862(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 * _L_lock_1871(void);
void _L_unlock_1892(void);
undefined8 _L_unlock_1946(void);
undefined8 _L_lock_1984(void);
void _L_unlock_2670(void);
void _L_lock_2716(void);
void _L_unlock_2744(void);
void _L_lock_2783(void);
undefined8 _L_unlock_4309(void);
undefined8 _L_lock_4346(void);
void _L_unlock_5237(void);
ulong _L_lock_5280(void);
ulong _L_unlock_5510(void);
void _L_lock_5564(void);
ulong _L_unlock_5725(void);
ulong _L_lock_5741(void);
ulong _L_lock_5888(void);
ulong _L_unlock_5905(void);
ulong _L_unlock_6089(void);
ulong _L_lock_6105(void);
long _L_unlock_7328(void);
long _L_lock_7406(void);
int * _L_unlock_8911(void);
int * _L_lock_8947(void);
undefined8 _L_unlock_9310(void);
undefined8 _L_lock_9322(void);
void * _L_unlock_9404(void);
void * _L_lock_9420(void);
void * _L_unlock_9498(void);
void * _L_lock_9512(void);
long _L_lock_9832(void);
long _L_unlock_9853(void);
long _L_lock_10407(void);
long _L_unlock_10429(void);
long * _L_lock_10618(void);
void _L_unlock_10866(void);
void _L_unlock_10906(void);
void _L_unlock_11226(void);
ulong _L_unlock_11446(void);
void _L_lock_11479(void);
ulong _L_unlock_11799(void);
ulong _L_lock_11813(void);
ulong _L_unlock_11853(void);
ulong _L_lock_11867(void);
long _L_unlock_13715(void);
long _L_lock_13749(void);
void _L_unlock_13814(void);
void _L_lock_13825(void);
undefined8 _L_unlock_13969(void);
undefined8 _L_lock_13982(void);
long _L_unlock_14339(void);
long _L_lock_14355(void);
long _L_unlock_14707(void);
long _L_lock_14723(void);
undefined8 _L_unlock_14990(void);
undefined8 _L_lock_15004(void);
long _L_unlock_15129(void);
long _L_lock_15143(void);
undefined8 _L_unlock_15284(void);
undefined8 _L_lock_15298(void);
long * _L_lock_15477(void);
long * _L_unlock_15491(void);
long * _L_lock_15525(void);
void _L_unlock_15619(void);
void _L_lock_16235(void);
void _L_lock_16256(undefined8 param_1,undefined8 param_2,int *param_3,undefined8 param_4,int param_5,int param_6);
void _L_unlock_16314(undefined8 param_1,undefined8 param_2,int *param_3);
void _L_unlock_16324(void);
undefined8 _L_unlock_16490(void);
long _L_lock_16520(void);
void _L_lock_16607(void);
void _L_unlock_16615(void);
void _L_lock_16823(void);
void _L_unlock_16909(void);
void * _L_lock_17325(void);
void * _L_unlock_17341(void);
undefined8 _L_unlock_17794(void);
long _L_lock_17838(void);
undefined8 * _L_lock_18023(void);
void _L_unlock_18083(void);
ulong _L_lock_18670(void);
undefined4 _L_unlock_18726(void);
void * _L_lock_19634(void);
void * _L_unlock_19650(void);
undefined8 _L_lock_20187(void);
undefined8 _L_unlock_20317(void);
undefined8 _L_unlock_20717(void);
long _L_lock_20753(void);
undefined8 _L_unlock_21049(void);
long _L_lock_21094(void);
uint _L_unlock_21343(undefined8 param_1,int *param_2);
uint _L_lock_21371(undefined8 param_1,undefined8 param_2,int *param_3);
void _L_lock_21728(void);
void _L_unlock_21738(void);
void _L_lock_21886(void);
void _L_unlock_21920(void);
undefined8 _L_lock_22240(void);
undefined8 _L_unlock_22456(void);
void * __default_morecore(intptr_t param_1);
char * strchr(char *__s,int __c);
char * __GI_strchr(ulong param_1,char param_2);
char * __strchr_sse42(undefined1 (*param_1) [16],uint param_2);
int strcmp(char *__s1,char *__s2);
ulong __GI_strcmp(char *param_1,char *param_2);
ulong __strcmp_sse42(char *param_1,char *param_2);
char * strcpy(char *__dest,char *__src);
ulong * __strcpy_sse2(ulong *param_1,ulong *param_2);
size_t strlen(char *__s);
char * strtok(char *__s,char *__delim);
void * memchr(void *__s,int __c,size_t __n);
int memcmp(void *__s1,void *__s2,size_t __n);
int __memcmp_sse2(ulong *param_1,byte *param_2,ulong param_3);
undefined1 * __memmove_sse2(undefined1 *param_1,ulong param_2,ulong param_3);
void * memmove(void *__dest,void *__src,size_t __n);
void * memset(void *__s,int __c,size_t __n);
void __memset_sse2(undefined4 *param_1,undefined1 param_2,ulong param_3);
void * mempcpy(void *__dest,void *__src,size_t __n);
void bcopy(void *__src,void *__dest,size_t __n);
void bzero(void *__s,size_t __n);
void * memcpy(void *__dest,void *__src,size_t __n);
void _wordcopy_fwd_aligned(undefined8 *param_1,undefined8 *param_2,long param_3);
void _wordcopy_fwd_dest_aligned(ulong *param_1,ulong param_2,long param_3);
void _wordcopy_bwd_aligned(long param_1,long param_2,long param_3);
void _wordcopy_bwd_dest_aligned(long param_1,ulong param_2,long param_3);
void * rawmemchr(void *__s,int __c);
char * __rawmemchr_sse2(char *param_1,char param_2);
undefined1  [16] __rawmemchr_sse42(ulong param_1,uint param_2);
char * strchrnul(char *__s,int __c);
ulong __strcmp_ssse3(char *param_1,char *param_2);
char * __strend_sse4(ulong param_1);
ulong __memcmp_sse4_1(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
undefined8 *__memmove_chk_ssse3(undefined8 *param_1,undefined8 *param_2,ulong param_3,ulong param_4);
undefined8 * __memmove_ssse3(undefined8 *param_1,undefined8 *param_2,ulong param_3);
undefined1 (*) [16]__memmove_chk_ssse3_back(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3,ulong param_4);
undefined1 (*) [16]__memmove_ssse3_back(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
void __memset_x86_64(undefined4 *param_1,undefined1 param_2,ulong param_3);
undefined1 (*) [16] __strcpy_ssse3(undefined1 (*param_1) [16],byte *param_2);
void __strcpy_sse2_unaligned(undefined1 (*param_1) [16],undefined1 (*param_2) [16]);
char * __strchr_sse2_no_bsf(ulong param_1,char param_2);
undefined1  [16] __memcmp_ssse3(char *param_1,char *param_2,ulong param_3);
void __memset_avx512_no_vzeroupper(undefined1 (*param_1) [64],uint param_2,ulong param_3);
undefined1 (*) [64]__memmove_chk_avx512_no_vzeroupper(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulong param_3,ulong param_4);
undefined1 (*) [64]__memmove_avx512_no_vzeroupper(undefined1 (*param_1) [64],undefined1 (*param_2) [64],ulong param_3);
long two_way_long_needle(long param_1,long param_2,void *param_3,ulong param_4);
char * strstr(char *__haystack,char *__needle);
uint intel_02_known_compare(byte *param_1,byte *param_2);
undefined1  [16] handle_amd(int param_1);
uint intel_check_word(int param_1,uint param_2,undefined1 *param_3,undefined1 *param_4);
long handle_intel.isra.0(int param_1);
undefined8 __cache_sysconf(void);
wchar_t * wmempcpy(wchar_t *__s1,wchar_t *__s2,size_t __n);
void _nl_cleanup_ctype(long param_1);
undefined8 __wcsmbs_getfct(undefined8 param_1,undefined8 param_2,ulong *param_3);
void __wcsmbs_load_conv(long param_1);
void __wcsmbs_clone_conv(long *param_1);
undefined8 __wcsmbs_named_conv(long *param_1,undefined8 param_2);
time_t time(time_t *__timer);
int gettimeofday(timeval *__tv,__timezone_ptr_t __tz);
uint sleep(uint __seconds);
undefined8 __libc_fork(void);
void _exit(int __status);
int execve(char *__path,char **__argv,char **__envp);
__pid_t getpid(void);
__uid_t getuid(void);
__pid_t setsid(void);
int sched_setparam(__pid_t __pid,sched_param *__param);
int sched_getparam(__pid_t __pid,sched_param *__param);
int sched_setscheduler(__pid_t __pid,int __policy,sched_param *__param);
int sched_getscheduler(__pid_t __pid);
int sched_yield(void);
int sched_get_priority_max(int __algorithm);
int sched_get_priority_min(int __algorithm);
undefined8 __exit_thread(uint param_1);
int __fxstat(int __ver,int __fildes,stat *__stat_buf);
int statfs(char *__file,statfs *__buf);
int access(char *__name,int __type);
int chdir(char *__path);
int link(char *__from,char *__to);
int unlink(char *__name);
int getrlimit64(__rlimit_resource_t __resource,rlimit *__rlimits);
void * sbrk(intptr_t __delta);
int ioctl(int __fd,ulong __request,...);
int getpagesize(void);
int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout);
undefined8 __select_nocancel(void);
char * mktemp(char *__template);
int usleep(__useconds_t __useconds);
char * decode_name(char *param_1);
undefined8 get_mnt_entry(FILE *param_1,undefined8 *param_2,char *param_3,int param_4);
void setmntent(char *param_1,char *param_2);
undefined8 endmntent(FILE *param_1);
undefined8 *getmntent_r(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined4 param_4);
bool addmntent(FILE *param_1,undefined8 *param_2);
char * hasmntopt(long param_1,char *param_2);
void cancel_handler(void);
void openlog_internal(long param_1,uint param_2,uint param_3);
void __vsyslog_chk(uint param_1,int param_2,char *param_3,__gnuc_va_list param_4);
void syslog(int __pri,char *__fmt,...);
void __syslog_chk(void);
void vsyslog(int __pri,char *__fmt,__gnuc_va_list __ap);
void openlog(char *__ident,int __option,int __facility);
void closelog(void);
int setlogmask(int __mask);
void _L_unlock_7(void);
void _L_lock_480(void);
void _L_unlock_507(void);
void _L_lock_1077(void);
void _L_lock_1143(void);
void * mmap64(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off64_t __offset);
int munmap(void *__addr,size_t __len);
int mprotect(void *__addr,size_t __len,int __prot);
int madvise(void *__addr,size_t __len,int __advice);
void trecurse(long param_1,code *UNRECOVERED_JUMPTABLE,ulong param_3);
void tdestroy_recurse(undefined8 *param_1,code *param_2);
void * tsearch(void *__key,void **__rootp,__compar_fn_t __compar);
void * tfind(void *__key,void **__rootp,__compar_fn_t __compar);
void * tdelete(void *__key,void **__rootp,__compar_fn_t __compar);
void twalk(void *__root,__action_fn_t __action);
void tdestroy(void *__root,__free_fn_t __freefct);
void * next_line(undefined4 param_1,void *param_2,long *param_3,long *param_4,long param_5);
void phys_pages_info(char *param_1);
int get_nprocs(void);
int get_nprocs_conf(void);
long get_phys_pages(void);
long get_avphys_pages(void);
void __init_misc(undefined8 param_1,undefined8 *param_2);
int clone(__fn *__fn,void *__child_stack,int __flags,void *__arg,...);
void FUN_0043c345(ulong param_1);
void * mremap(void *__addr,size_t __old_len,size_t __new_len,int __flags,...);
int prctl(int __option,...);
int getsockname(int __fd,sockaddr *__addr,socklen_t *__len);
int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen);
int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen);
int socket(int __domain,int __type,int __protocol);
bool __libc_alloca_cutoff(ulong param_1);
void __libc_enable_asynccancel(void);
void __libc_disable_asynccancel(ulong param_1);
byte __register_atfork(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
void __linkin_atfork(long *param_1);
byte _L_lock_98(void);
byte _L_unlock_195(void);
undefined4 * __libc_pthread_init(undefined8 param_1,undefined8 param_2);
undefined8 __inet_aton_exact(char *param_1,uint *param_2);
int inet_aton(char *__cp,in_addr *__inp);
in_addr_t inet_addr(char *__cp);
void __res_init(void);
uint __res_randomid(void);
ulong __res_iclose(long param_1,char param_2);
void __res_nclose(long param_1);
undefined4 maybe_init(undefined8 *param_1,char param_2);
undefined8 * __resolv_context_get(void);
undefined8 * __resolv_context_get_preinit(void);
undefined8 * __resolv_context_get_override(undefined8 param_1);
void __resolv_context_put(void *param_1);
void __resolv_context_freeres(void);
undefined8 * get_locked_global(void);
void put_locked_global.isra.1(void);
long * __resolv_conf_get_current(void);
void __resolv_conf_put(long *param_1);
long * __resolv_conf_get(long param_1);
undefined8 * __resolv_conf_allocate(long param_1);
undefined8 __resolv_conf_attach(undefined4 *param_1,long *param_2);
void __resolv_conf_detach(long param_1);
undefined8 * _L_lock_11(void);
void _L_unlock_154(void);
void _L_lock_359(void);
void _L_unlock_377(void);
undefined8 backtrace_helper(undefined8 param_1,long *param_2);
int backtrace(long param_1,int param_2);
void backtrace_symbols_fd(ulong *param_1,int param_2,int param_3);
ulong __vfprintf_chk(FILE *param_1,int param_2,char *param_3,__gnuc_va_list param_4);
ulong _L_lock_46(void);
undefined4 _L_unlock_115(undefined8 param_1,undefined4 param_2,undefined8 param_3);
void _L_unlock_173(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void __chk_fail(void);
void __fortify_fail(undefined8 param_1);
uint32_t htonl(uint32_t __netlong);
uint16_t htons(uint16_t __netshort);
char * inet_ntoa(in_addr __in);
hostent * gethostbyname(char *__name);
hostent * _L_lock_34(void);
undefined8 _L_unlock_120(void);
int gethostbyname_r(char *__name,hostent *__result_buf,char *__buf,size_t __buflen,hostent **__result,int *__h_errnop);
int nscd_gethst_r(undefined8 param_1,undefined8 param_2,uint param_3,ulong *param_4,long param_5,ulong param_6,undefined8 *param_7,undefined4 *param_8);
void __nscd_gethostbyname_r(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
void __nscd_gethostbyname2_r(char *param_1,int param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7);
undefined8 __nscd_gethostbyaddr_r(undefined8 param_1,int param_2,int param_3);
undefined4 __nscd_get_nl_timestamp(void);
void wait_on_socket(int param_1,long param_2);
int open_socket(undefined4 param_1,void *param_2,size_t param_3);
long __readall(int param_1,void *param_2,size_t param_3);
ulong __readvall(int param_1,iovec *param_2,int param_3);
void __nscd_unmap(undefined8 *param_1);
int * __nscd_get_mapping(undefined4 param_1,char *param_2,long *param_3);
long * __nscd_get_map_ref(undefined4 param_1,undefined8 param_2,int *param_3,uint *param_4);
int * __nscd_cache_search(uint param_1,void *param_2,size_t param_3,long *param_4,long param_5);
int __nscd_open_socket(undefined8 param_1,ulong param_2,undefined4 param_3,void *param_4,size_t param_5);
void _dl_next_tls_modid(void);
long _dl_count_modids(void);
void _dl_get_tls_static_info(undefined8 *param_1,undefined8 *param_2);
undefined8 * _dl_allocate_tls_storage(void);
long _dl_allocate_tls_init(long param_1);
void _dl_allocate_tls(undefined8 *param_1);
void _dl_deallocate_tls(long param_1,char param_2);
ulong _dl_tls_get_addr_soft(long param_1);
void _dl_add_to_slotinfo(ulong param_1);
int _dl_make_stack_executable(ulong *param_1);
undefined1  [16] init_cpu_features.constprop.1(void);
void _dl_aux_init(long *param_1);
void _dl_non_dynamic_init(void);
undefined8 _dl_addr(ulong param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4);
undefined8 _dl_addr_inside_object(long *param_1,long param_2);
void __libc_init_secure(void);
void _dl_mcount_wrapper(undefined8 param_1);
void _dl_mcount_wrapper_check(undefined8 param_1);
uint _dl_discover_osversion(void);
void __libc_init_first(undefined4 param_1,undefined8 param_2,undefined8 param_3);
void _dl_start(void);
void __gconv_alias_compare(undefined8 *param_1,undefined8 *param_2);
void derivation_compare(undefined8 *param_1,undefined8 *param_2);
undefined4 find_derivation(char *param_1,char *param_2,char *param_3,char *param_4,ulong *param_5,ulong *param_6);
undefined8 __gconv_get_modules_db(void);
undefined8 __gconv_get_alias_db(void);
void __gconv_release_step(long *param_1);
int __gconv_compare_alias(char *param_1,char *param_2);
ulong __gconv_find_transform(char *param_1,char *param_2,long *param_3,undefined8 param_4,uint param_5);
undefined8 __gconv_close_transform(long param_1,long param_2);
ulong _L_lock_4356(void);
undefined4 _L_unlock_4374(void);
uint _L_unlock_4480(void);
undefined8 _L_unlock_4531(void);
undefined8 _L_unlock_4665(void);
undefined8 _L_lock_4707(void);
undefined8 _L_unlock_4799(void);
void insert_module(undefined8 *param_1,int param_2);
void add_module.isra.1(char *param_1,void *param_2,size_t param_3,undefined4 param_4);
void __gconv_get_path(void);
void __gconv_read_conf(void);
void _L_lock_810(void);
void _L_unlock_822(void);
void __gconv_get_builtin_trans(byte *param_1,undefined8 *param_2);
ulong __gconv_btwoc_ascii(undefined8 param_1,byte param_2);
ulong __gconv_transform_internal_ucs4(long param_1,undefined8 *param_2,long *param_3,undefined1 *param_4,undefined8 *param_5,undefined8 param_6,int param_7,int param_8);
ulong __gconv_transform_ucs4_internal(long param_1,undefined8 *param_2,long *param_3,uint *param_4,undefined8 *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_internal_ucs4le(long param_1,undefined8 *param_2,long *param_3,undefined1 *param_4,undefined8 *param_5,undefined8 param_6,int param_7,int param_8);
ulong __gconv_transform_ucs4le_internal(long param_1,undefined8 *param_2,long *param_3,int *param_4,undefined8 *param_5,long *param_6,int param_7,int param_8);
int __gconv_transform_ascii_internal(long param_1,ulong *param_2,long *param_3,byte *param_4,ulong *param_5,long *param_6,int param_7,undefined4 param_8);
ulong __gconv_transform_internal_ascii(long param_1,ulong *param_2,ulong *param_3,uint *param_4,ulong *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_internal_utf8(long param_1,undefined8 *param_2,long *param_3,uint *param_4,undefined8 *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_utf8_internal(long param_1,ulong *param_2,ulong *param_3,byte *param_4,ulong *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_ucs2_internal(long param_1,ulong *param_2,ulong *param_3,ushort *param_4,ulong *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_internal_ucs2(long param_1,ulong *param_2,ulong *param_3,uint *param_4,ulong *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_ucs2reverse_internal(long param_1,ulong *param_2,ulong *param_3,ushort *param_4,ulong *param_5,long *param_6,int param_7,int param_8);
ulong __gconv_transform_internal_ucs2reverse(long param_1,ulong *param_2,ulong *param_3,uint *param_4,ulong *param_5,long *param_6,int param_7,int param_8);
undefined8 __gconv_get_cache(void);
undefined8 __gconv_load_cache(void);
int __gconv_compare_alias_cache(char *param_1,char *param_2,int *param_3);
ulong __gconv_lookup_cache(char *param_1,char *param_2,undefined8 *param_3,ulong *param_4,uint param_5);
void __gconv_release_cache(void *param_1);
void known_compare(undefined8 *param_1,undefined8 *param_2);
void do_release_shlib(long *param_1,int param_2);
undefined8 * __gconv_find_shlib(char *param_1);
void __gconv_release_shlib(undefined8 param_1);
char * new_composite_name(int param_1,undefined8 *param_2);
char * setlocale(int __category,char *__locale);
long _nl_find_locale(char *param_1,undefined8 *param_2,int param_3,undefined8 *param_4);
void _nl_remove_locale(int param_1,long param_2);
void * _nl_intern_locale_data(uint param_1,uint *param_2,ulong param_3);
undefined8 * _nl_load_locale(undefined8 *param_1,undefined4 param_2);
void _nl_unload_locale(undefined8 *param_1);
undefined8 _nl_load_locale_from_archive(int param_1,undefined8 *param_2);
void _nl_postload_ctype(void);
long _nl_find_domain(char *param_1,void *param_2,undefined8 param_3,undefined8 param_4);
void _nl_load_domain(long *param_1,undefined8 param_2);
void _L_lock_45(void);
void _L_unlock_84(void);
void alias_compare(undefined8 *param_1,undefined8 *param_2);
long read_alias_file(void *param_1,int param_2);
undefined8 _nl_expand_alias(undefined8 param_1);
undefined8 _L_lock_670(void);
undefined8 _L_unlock_754(void);
undefined8 *_nl_make_l10nflist(undefined8 *param_1,char *param_2,size_t param_3,uint param_4,char *param_5,char *param_6,char *param_7,char *param_8,char *param_9,char *param_10,int param_11);
void _nl_normalize_codeset(byte *param_1,long param_2);
uint _nl_explode_name(byte *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,undefined8 *param_5,undefined8 *param_6);
void __gettext_free_exp(int *param_1);
undefined4 * new_exp.constprop.2(undefined4 param_1,long *param_2);
undefined8 __gettextparse(long *param_1);
void __gettext_extract_plural(char *param_1,undefined8 *param_2,ulonglong *param_3);
void __hash_string(byte *param_1);
void __setfpucw(void);
void __sigsetjmp(undefined8 *param_1);
undefined8 __sigjmp_save(long param_1,int param_2);
void * bsearch(void *__key,void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar);
void msort_with_tmp.part.0(size_t *param_1,undefined8 *param_2,ulong param_3);
void qsort_r(void *__base,size_t __nmemb,size_t __size,__compar_d_fn_t __compar,void *__arg);
void qsort(void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar);
char * getenv(char *__name);
ulong __add_to_environ(char *param_1,char *param_2,void *param_3,undefined4 param_4);
int setenv(char *__name,char *__value,int __replace);
int unsetenv(char *__name);
int clearenv(void);
undefined4 _L_lock_53(void);
undefined8 _L_unlock_164(void);
undefined8 _L_unlock_404(void);
undefined4 _L_unlock_537(void);
undefined8 _L_lock_819(void);
undefined8 _L_unlock_863(void);
undefined8 _L_lock_945(void);
undefined8 _L_unlock_957(void);
char * _itoa_word(ulong param_1,char *param_2,uint param_3,int param_4);
undefined1 * _fitoa_word(ulong param_1,undefined1 *param_2,uint param_3,int param_4);
uint _IO_helper_overflow(_IO_FILE *param_1,byte param_2);
int vfprintf(FILE *__s,char *__format,__gnuc_va_list __arg);
int buffered_vfprintf(uint *param_1,char *param_2,__gnuc_va_list param_3);
ulong _L_lock_1022(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_unlock_1235(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_unlock_13791(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_lock_13814(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
int hack_digit.13299(void);
int __printf_fp_l(_IO_FILE *param_1,wchar_t *param_2,uint *param_3,undefined8 *param_4);
void __printf_fp(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined1  [16] __guess_grouping(uint param_1,byte *param_2);
ulong register_printf_specifier(uint param_1,undefined8 param_2,undefined8 param_3);
ulong register_printf_function(uint param_1,undefined8 param_2,undefined8 param_3);
ulong _L_lock_26(void);
undefined4 _L_unlock_48(void);
int __printf_fphex(_IO_FILE *param_1,int *param_2,undefined8 *param_3);
ulong register_printf_modifier(uint *param_1);
bool __handle_registered_modifier_mb(undefined8 *param_1,long param_2);
bool __handle_registered_modifier_wc(undefined8 *param_1,long param_2);
ulong _L_lock_136(void);
undefined4 _L_unlock_188(void);
ulong register_printf_type(undefined8 param_1);
ulong _L_lock_16(void);
undefined4 _L_unlock_42(void);
int fprintf(FILE *__stream,char *__format,...);
int snprintf(char *__s,size_t __maxlen,char *__format,...);
int dprintf(int __fd,char *__fmt,...);
int _IO_vfscanf(_IO_FILE *param_1,char *param_2,__gnuc_va_list param_3,int *param_4);
int vfscanf(FILE *__s,char *__format,__gnuc_va_list __arg);
undefined4 _L_unlock_1261(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_lock_1486(void);
undefined8 __path_search(char *param_1,ulong param_2,char *param_3,char *param_4,int param_5);
int __gen_tempname(char *param_1,int param_2,uint param_3,int param_4);
long __parse_one_specmb(long param_1,uint param_2,uint *param_3,ulong *param_4);
uint __isnanl_pseudo(void);
undefined1 * _IO_file_doallocate(uint *param_1);
int fflush(FILE *__stream);
ulong _L_lock_39(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
undefined4 _L_unlock_113(undefined8 param_1,undefined8 param_2);
void _L_unlock_215(undefined8 param_1,undefined8 param_2,undefined8 param_3);
int fputs(char *__s,FILE *__stream);
ulong _L_lock_51(void);
undefined4 _L_unlock_147(undefined8 param_1,undefined8 param_2);
void _L_unlock_245(undefined8 param_1,undefined8 param_2,undefined8 param_3);
long ftell(FILE *__stream);
long _L_lock_32(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
long _L_unlock_152(undefined8 param_1,undefined8 param_2);
void _L_unlock_200(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined1 * _IO_wfile_doallocate(byte *param_1);
size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s);
ulong _L_lock_62(void);
ulong _L_unlock_318(undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
void _L_unlock_372(undefined8 param_1,undefined8 param_2,undefined8 param_3);
__ssize_t _IO_padn(_IO_FILE *param_1,int param_2,__ssize_t param_3);
undefined8 _IO_seekoff_unlocked(_IO_FILE *param_1,char *param_2,ulong param_3,ulong param_4);
__off64_t _IO_seekoff(_IO_FILE *param_1,__off64_t param_2,int param_3,int param_4);
undefined8 _L_lock_297(void);
undefined8 _L_unlock_451(undefined8 param_1,undefined8 param_2);
void _L_unlock_617(undefined8 param_1,undefined8 param_2,undefined8 param_3);
long _IO_wpadn(long param_1,int param_2,int param_3);
undefined8 save_for_wbackup.isra.0(long *param_1,long *param_2,long param_3);
void _IO_least_wmarker(long param_1,long param_2);
void _IO_switch_to_main_wget_area(uint *param_1);
void _IO_switch_to_wbackup_area(uint *param_1);
void _IO_wsetb(long param_1,undefined8 param_2,undefined8 param_3,int param_4);
wchar_t _IO_wdefault_pbackfail(uint *param_1,wchar_t param_2);
void _IO_wdefault_finish(long param_1);
undefined4 _IO_wdefault_uflow(long param_1);
void __woverflow(long param_1,undefined4 param_2);
ulong __wuflow(uint *param_1);
ulong __wunderflow(uint *param_1);
long _IO_wdefault_xsputn(long param_1,wchar_t *param_2,ulong param_3);
long _IO_wdefault_xsgetn(uint *param_1,wchar_t *param_2,ulong param_3);
void _IO_wdoallocbuf(byte *param_1);
undefined1 * _IO_wdefault_doallocate(long param_1);
undefined8 _IO_switch_to_wget_mode(uint *param_1);
void _IO_free_wbackup_area(uint *param_1);
void _IO_sputbackwc(uint *param_1,int param_2);
void _IO_sungetwc(uint *param_1);
int _IO_adjust_wcolumn(int param_1,int *param_2,int param_3);
void _IO_init_wmarker(undefined8 *param_1,uint *param_2);
int _IO_wmarker_delta(long param_1);
undefined8 _IO_seekwmark(uint *param_1,long param_2);
void _IO_unsave_wmarkers(uint *param_1);
int do_encoding(long param_1);
undefined8 do_always_noconv(void);
undefined4 do_max_length(long param_1);
undefined8 do_in(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8);
undefined8 do_unshift(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 *param_5);
undefined8 do_out(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8);
long do_length(long param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5);
void _IO_fwide(long param_1,int param_2);
int fseek(FILE *__stream,long __off,int __whence);
ulong _L_lock_39(void);
undefined4 _L_unlock_93(undefined8 param_1,undefined8 param_2);
void _L_unlock_147(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 _IO_mem_sync(long param_1);
void _IO_mem_finish(long param_1);
FILE * open_memstream(char **__bufloc,size_t *__sizeloc);
int vdprintf(int __fd,char *__fmt,__gnuc_va_list __arg);
undefined4 _IO_strn_overflow(long param_1,undefined4 param_2);
int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg);
char * fgets_unlocked(char *__s,int __n,FILE *__stream);
int fputs_unlocked(char *__s,FILE *__stream);
void __libc_dynarray_at_failure(undefined8 param_1,undefined8 param_2);
undefined8 __libc_dynarray_emplace_enlarge(long *param_1,void *param_2,ulong param_3);
ulong __libc_alloc_buffer_alloc_array(ulong *param_1,ulong param_2,long param_3,ulong param_4);
undefined1  [16] __libc_alloc_buffer_allocate(size_t param_1,undefined8 *param_2);
void __libc_alloc_buffer_copy_string(undefined8 param_1,undefined8 param_2,char *param_3);
void __libc_alloc_buffer_create_failure(undefined8 param_1,undefined8 param_2);
char * strdup(char *__s);
char * strndup(char *__string,size_t __n);
char * strerror_r(int __errnum,char *__buf,size_t __buflen);
size_t strnlen(char *__string,size_t __maxlen);
char * __GI_strnlen(ulong param_1,char *param_2);
int strncmp(char *__s1,char *__s2,size_t __n);
char * rindex(char *__s,int __c);
char * stpcpy(char *__dest,char *__src);
ulong * __stpcpy_sse2(ulong *param_1,ulong *param_2);
int strcasecmp_l(char *__s1,char *__s2,__locale_t __loc);
int strcasecmp(char *__s1,char *__s2);
ulong __strcasecmp_sse2(undefined1 (*param_1) [16],undefined1 (*param_2) [16]);
ulong __strcasecmp_l_sse2(undefined1 (*param_1) [16],undefined1 (*param_2) [16],long *param_3);
ulong __strcasecmp_sse42(undefined1 (*param_1) [16],undefined1 (*param_2) [16]);
ulong __strcasecmp_l_sse42(undefined1 (*param_1) [16],undefined1 (*param_2) [16],long *param_3);
ulong __strcasecmp_avx(undefined1 (*param_1) [16],undefined1 (*param_2) [16]);
ulong __strcasecmp_l_avx(undefined1 (*param_1) [16],undefined1 (*param_2) [16],long *param_3);
long two_way_long_needle(long param_1,long param_2,void *param_3,ulong param_4);
void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen);
long argz_count(char *param_1,long param_2);
undefined8 argz_create_sep(char *param_1,int param_2,undefined8 *param_3,ulong *param_4);
void argz_stringify(char *param_1,size_t param_2,char param_3);
undefined8 argz_add_sep(undefined8 *param_1,long *param_2,char *param_3,int param_4);
ulong __strcasecmp_ssse3(undefined1 (*param_1) [16],undefined1 (*param_2) [16]);
ulong __strcasecmp_l_ssse3(undefined1 (*param_1) [16],undefined1 (*param_2) [16],long *param_3);
undefined1 (*) [16] __stpcpy_ssse3(undefined1 (*param_1) [16],byte *param_2);
void __stpcpy_sse2_unaligned(undefined1 (*param_1) [16],undefined1 (*param_2) [16]);
ulong __strnlen_sse2_no_bsf(char *param_1,ulong param_2);
int __strcasecmp_l_nonascii(byte *param_1,byte *param_2,long param_3);
int __strcasecmp_nonascii(byte *param_1,byte *param_2);
wchar_t * wmemcpy(wchar_t *__s1,wchar_t *__s2,size_t __n);
wchar_t * wmemmove(wchar_t *__s1,wchar_t *__s2,size_t __n);
wchar_t * wmemset(wchar_t *__s,wchar_t __c,size_t __n);
size_t mbrlen(char *__s,size_t __n,mbstate_t *__ps);
size_t mbrtoc32(wchar_t *__pwc,char *__s,size_t __n,mbstate_t *__p);
size_t wcrtomb(char *__s,wchar_t __wc,mbstate_t *__ps);
size_t wcsrtombs(char *__dst,wchar_t **__src,size_t __len,mbstate_t *__ps);
size_t wcsnlen(wchar_t *__s,size_t __maxlen);
tm * localtime_r(time_t *__timer,tm *__tp);
tm * localtime(time_t *__timer);
int compute_offset(uint param_1,uint param_2,uint param_3);
undefined8 parse_tzname(long *param_1,int param_2);
bool parse_rule(undefined8 *param_1,int param_2);
undefined8 * __tzstring(char *param_1);
void __tzset_parse_tz(char *param_1);
void tzset_internal(int param_1,int param_2);
undefined8 __tzname_max(void);
void __tz_compute(long param_1,long param_2,int param_3);
void tzset(void);
int * __tz_convert(undefined8 *param_1,int param_2,int *param_3);
undefined8 _L_lock_1554(void);
undefined8 _L_unlock_1564(void);
void _L_lock_2461(void);
void _L_unlock_2481(void);
int * _L_lock_2517(void);
int * _L_unlock_2557(void);
void __tzfile_read(char *param_1,ulong param_2,long *param_3);
void __tzfile_default(char *param_1,char *param_2,long param_3,long param_4);
void __tzfile_compute(long param_1,int param_2,long *param_3,int *param_4,long param_5);
long __strftime_internal(byte *param_1,long param_2,byte *param_3,uint *param_4,char *param_5,long param_6);
size_t strftime_l(char *__s,size_t __maxsize,char *__format,tm *__tp,__locale_t __loc);
void _nl_init_era_entries.part.0(long param_1);
long _nl_get_era_entry(long param_1,long param_2);
long _nl_select_era_entry(int param_1,long param_2);
undefined8 _nl_get_alt_digit(uint param_1,long param_2);
undefined8 _nl_get_walt_digit(uint param_1,long param_2);
ulong _nl_parse_alt_digit(long *param_1,long param_2);
void _nl_cleanup_time(long param_1);
int * __opendirat(undefined8 param_1,char *param_2);
DIR * opendir(char *__name);
int * __alloc_dir(int param_1,char param_2,uint param_3,long param_4);
int closedir(DIR *__dirp);
dirent64 * readdir64(DIR *__dirp);
long * _L_lock_29(void);
undefined8 _L_unlock_112(void);
undefined8 __getdents64(undefined8 param_1,ulong param_2);
int uname(utsname *__name);
__uid_t geteuid(void);
__gid_t getgid(void);
__gid_t getegid(void);
ulong __sysconf_check_spec(char *param_1);
long sysconf(int __name);
rlim_t __get_child_max(void);
int __xstat(int __ver,char *__filename,stat64 *__stat_buf);
int __lxstat64(int __ver,char *__filename,stat *__stat_buf);
int mkdir(char *__path,__mode_t __mode);
undefined1  [16] __openat_nocancel(undefined8 param_1,undefined8 param_2,int param_3);
int openat(int __fd,char *__file,int __oflag,...);
char * getcwd(char *__buf,size_t __size);
int isatty(int __fd);
int poll(pollfd *__fds,nfds_t __nfds,int __timeout);
undefined8 __poll_nocancel(void);
int tcgetattr(int __fd,termios *__termios_p);
int brk(void *__addr);
ssize_t readv(int __fd,iovec *__iovec,int __count);
ssize_t writev(int __fd,iovec *__iovec,int __count);
int getdtablesize(void);
int __getclktck(void);
wctrans_t wctrans(char *__property);
wint_t towctrans(wint_t __wc,wctrans_t __desc);
void res_setoptions(long param_1,byte *param_2);
undefined8 __resolv_conf_load(undefined4 *param_1);
int __res_ninit(undefined8 param_1);
undefined8 __res_vinit(int *param_1,int param_2);
char * arg_trimdomain_list(undefined8 param_1,ulong param_2,char *param_3);
void do_init(void);
void _res_hconf_init(void);
void _res_hconf_reorder_addrs(long param_1);
void _res_hconf_trim_domain(char *param_1);
void _res_hconf_trim_domains(undefined8 *param_1);
void _L_lock_1604(void);
void _L_unlock_1621(void);
int known_compare(undefined8 *param_1,undefined8 *param_2);
undefined8 nss_parse_service_list(char *param_1);
int __nss_database_lookup(char *param_1,char *param_2,char *param_3,long *param_4);
undefined8 __nss_configure_lookup(char *param_1,undefined8 param_2);
ulong __nss_lookup_function(long param_1,char *param_2);
int __nss_lookup(long *param_1,undefined8 param_2,long param_3,long *param_4);
undefined8 __nss_next2(long *param_1,undefined8 param_2,long param_3,long *param_4,int param_5,int param_6);
int _L_lock_907(void);
undefined8 _L_unlock_918(void);
int _L_unlock_1000(void);
undefined4 _L_lock_1490(void);
undefined4 _L_unlock_1499(void);
ulong _L_lock_1549(void);
undefined8 _L_unlock_1587(void);
undefined8 __nss_next(long *param_1,undefined8 param_2,long *param_3,int param_4,int param_5);
undefined8 __nss_hostname_digits_dots(char *param_1,undefined8 *param_2,undefined8 *param_3,size_t *param_4,ulong param_5,undefined8 *param_6,undefined4 *param_7,int param_8,undefined4 *param_9);
undefined8 __nss_hostname_digits_dots_context(undefined8 param_1,char *param_2,undefined8 *param_3,undefined8 *param_4,size_t *param_5,ulong param_6,undefined8 *param_7,undefined4 *param_8,int param_9,undefined4 *param_10);
undefined8 __nss_hosts_lookup2(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 __nss_hosts_lookup(long *param_1,undefined8 param_2,undefined8 param_3);
undefined8 __readonly_area(ulong param_1,long param_2);
in_addr inet_makeaddr(in_addr_t __net,in_addr_t __host);
undefined8 __inet6_scopeid_pton(uint *param_1,char *param_2,undefined4 *param_3);
void __ifreq(undefined8 *param_1,int *param_2,int param_3);
uint32_t __nis_hash(void *__keyarg,size_t __len);
size_t is_dst(char *param_1,char *param_2);
void lose(undefined4 param_1,int param_2,undefined8 param_3,void *param_4,void *param_5,undefined8 param_6,long param_7);
int open_verify.isra.4(char *param_1,ulong *param_2,ulong param_3,undefined1 *param_4,undefined4 param_5);
undefined8 open_path.isra.5(undefined8 param_1,ulong param_2,uint param_3,long *param_4,undefined8 param_5,undefined8 param_6);
void add_name_to_object.isra.2(undefined8 *param_1,char *param_2);
long * _dl_map_object_from_fd.isra.6(char *param_1,int param_2,ulong *param_3,void *param_4,undefined8 param_5,undefined4 param_6,uint param_7,undefined8 param_8,long param_9);
long _dl_dst_count(char *param_1);
char * _dl_dst_substitute(long param_1,char *param_2,char *param_3);
void * expand_dynamic_string_token(long param_1,char *param_2);
undefined8 *fillin_rpath(char *param_1,undefined8 *param_2,char *param_3,undefined8 param_4,char *param_5,undefined8 param_6);
long cache_rpath.part.7(long param_1,undefined8 *param_2,int param_3,undefined8 param_4);
void _dl_init_paths(char *param_1);
long _dl_map_object(long param_1,char *param_2,undefined4 param_3,int param_4,uint param_5,long param_6);
void _dl_rtld_di_serinfo(long param_1,long *param_2,char param_3);
uint * check_match.9769(uint *param_1);
undefined8 do_lookup_x(byte *param_1,ulong param_2,ulong *param_3,undefined8 param_4,long *param_5,long *param_6,ulong param_7,long param_8,undefined8 param_9,long param_10,uint param_11,undefined8 param_12);
uint * _dl_lookup_symbol_x(byte *param_1,uint *param_2,long *param_3,long *param_4,long *param_5,int param_6,uint param_7,long param_8);
void _dl_setup_hash(long param_1);
void _dl_add_to_namespace_list(long param_1,long param_2);
void * _dl_new_object(char *param_1,char *param_2,byte param_3,void *param_4,uint param_5,long param_6);
undefined8 _dl_try_allocate_static_tls(long param_1);
void _dl_allocate_static_tls(long param_1);
void _dl_nothread_init_static_tls(long param_1);
void _dl_protect_relro(long *param_1);
void _dl_reloc_bad_type(long param_1,uint param_2,int param_3);
void _dl_relocate_object(ulong *param_1,undefined8 param_2,uint param_3,int param_4,ulong *param_5);
undefined8 *_dl_important_hwcaps(long param_1,undefined8 *param_2,ulong *param_3,undefined8 *param_4);
void _dl_signal_error(int param_1,char *param_2,char *param_3,char *param_4);
void _dl_signal_cerror(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
int _dl_catch_error(undefined8 *param_1,undefined8 *param_2,undefined1 *param_3,code *param_4,undefined8 param_5);
void _dl_receive_error(undefined8 param_1,code *param_2,undefined8 param_3);
void _dl_debug_state(void);
void _dl_debug_initialize(long param_1,long param_2);
undefined1  [16] _dl_debug_vdprintf(undefined4 param_1,int param_2,char *param_3,uint *param_4);
void * _dl_sysdep_read_whole_file(char *param_1,size_t *param_2,int param_3);
void _dl_debug_printf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
void _dl_debug_printf_c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
void _dl_dprintf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
undefined8 _dl_name_match_p(char *param_1,long param_2);
uint _dl_higher_prime_number(ulong param_1);
void _dl_start_profile(void);
void _dl_mcount(long param_1,long param_2);
undefined2 * _dl_get_origin(void);
undefined8 _dl_scope_free(void *param_1);
undefined1  [16]_dl_runtime_profile_avx512(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8);
undefined1  [16]_dl_runtime_profile_avx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8);
undefined8 _dl_runtime_profile_sse(undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14,undefined8 param_15,undefined8 param_16);
void _dl_runtime_resolve_fxsave(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7);
void _dl_runtime_resolve_xsave(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7);
void _dl_runtime_resolve_xsavec(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7);
int _dl_cache_libcmp(char *param_1,char *param_2);
char * _dl_load_cache_lookup(undefined8 param_1);
void _dl_unload_cache(void);
void _dl_process_tunable_env_entries(void);
undefined8 _dl_tlsdesc_return(void);
long FUN_0048aa15(void);
long _dl_tlsdesc_undefweak(void);
void FUN_0048aa2e(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
void _dl_tlsdesc_resolve_rela(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
void FUN_0048aa9f(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
void _dl_tlsdesc_resolve_hold(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6);
void do_dlopen(undefined8 *param_1);
void do_dlsym_private(long *param_1);
void do_dlsym(long *param_1);
void do_dlclose(long param_1);
int __libc_dlclose(undefined8 param_1);
long __libc_dlsym(undefined8 param_1,undefined8 param_2);
void * __libc_dlopen_mode(undefined8 param_1,undefined4 param_2);
long __libc_dlsym_private(undefined8 param_1,undefined8 param_2);
void __libc_register_dl_open_hook(undefined8 param_1);
long _dl_initial_error_catch_tsd(void);
void __gconv_close(undefined8 *param_1);
int __gconv_transliterate(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,long *param_5,uint *param_6,undefined8 *param_7,long *param_8);
undefined8 __gconv_translit_find(void);
void dcgettext(undefined8 param_1,undefined8 param_2,undefined4 param_3);
ulong plural_eval(int *param_1,ulong param_2);
int transcmp(undefined8 *param_1,undefined8 *param_2);
ulong * _nl_find_msg(long param_1,long param_2,char *param_3,int param_4,ulong *param_5);
char * __dcigettext(char *param_1,char *param_2,char *param_3,int param_4,long param_5,uint param_6);
undefined8 _L_unlock_771(void);
undefined8 _L_unlock_1303(void);
undefined8 _L_lock_1459(void);
undefined8 _L_unlock_2124(void);
undefined8 _L_lock_2430(void);
undefined8 _L_unlock_2441(void);
int isinf(double __value);
int isnan(double __value);
uint isinfl(void);
int isnanl(void);
void _quicksort(undefined1 *param_1,ulong param_2,ulong param_3,code *param_4,undefined8 param_5);
void __strtof_internal(void);
float strtof(char *__nptr,char **__endptr);
void __strtod_internal(void);
double strtod(char *__nptr,char **__endptr);
void __strtold_internal(void);
double strtold(char *__nptr,char **__endptr);
char * str_to_mpn.isra.0(char *param_1,int param_2,ulong *param_3,long *param_4,long *param_5,long param_6,char *param_7);
undefined8 round_and_return(undefined4 param_1,ulong *param_2,ulong param_3,int param_4,ulong param_5,byte param_6,uint param_7);
ulong ____strtof_l_internal(byte *param_1,long *param_2,int param_3,long param_4);
float strtof_l(char *__nptr,char **__endptr,__locale_t __loc);
char * str_to_mpn.isra.0(char *param_1,int param_2,ulong *param_3,long *param_4,long *param_5,long param_6,char *param_7);
undefined8 round_and_return(undefined8 param_1,ulong *param_2,ulong param_3,int param_4,ulong param_5,byte param_6,uint param_7);
undefined8 ____strtod_l_internal(byte *param_1,long *param_2,int param_3,long param_4);
double strtod_l(char *__nptr,char **__endptr,__locale_t __loc);
char * str_to_mpn.isra.0(char *param_1,int param_2,ulong *param_3,long *param_4,long *param_5,long param_6,char *param_7);
void round_and_return(ulong *param_1,ulong param_2,int param_3,ulong param_4,byte param_5,uint param_6);
void ____strtold_l_internal(byte *param_1,long *param_2,int param_3,long param_4);
double strtold_l(char *__nptr,char **__endptr,__locale_t __loc);
uint __strtof_nan(byte *param_1,undefined8 *param_2,byte param_3);
ulong __strtod_nan(byte *param_1,undefined8 *param_2,byte param_3);
void __strtold_nan(byte *param_1,undefined8 *param_2,byte param_3);
bool __mpn_add_n(long param_1,ulong *param_2,ulong *param_3,ulong param_4);
int __mpn_cmp(long param_1,long param_2,long param_3);
ulong __mpn_divrem(long param_1,long param_2,ulong *param_3,long param_4,ulong *param_5,long param_6);
ulong __mpn_lshift(long param_1,long param_2,ulong param_3,byte param_4);
ulong __mpn_rshift(ulong *param_1,ulong *param_2,ulong param_3,byte param_4);
undefined8 __mpn_mul(void *param_1,long param_2,long param_3,ulong *param_4,long param_5);
undefined8 __mpn_mul_1(undefined8 *param_1,ulong *param_2,ulong param_3,ulong param_4);
void __mpn_impn_mul_n_basecase(void *param_1,long param_2,ulong *param_3,long param_4);
void __mpn_impn_mul_n(long param_1,long param_2,long param_3,ulong param_4,long param_5);
void __mpn_impn_sqr_n_basecase(void *param_1,ulong *param_2,long param_3);
void __mpn_impn_sqr_n(long param_1,long param_2,ulong param_3,long param_4);
void __mpn_mul_n(undefined8 param_1,long param_2,long param_3,long param_4);
bool __mpn_sub_n(long param_1,ulong *param_2,ulong *param_3,ulong param_4);
long __mpn_submul_1(ulong *param_1,ulong *param_2,long param_3,ulong param_4);
undefined8 __mpn_extract_double(ulong param_1,ulong *param_2,undefined8 param_3,int *param_4,uint *param_5);
undefined8 __mpn_extract_long_double(ulong *param_1,undefined8 param_2,int *param_3,uint *param_4,undefined8 param_5,undefined8 param_6,unkuint10 param_7);
uint __mpn_construct_float(undefined8 *param_1,int param_2,int param_3);
ulong __mpn_construct_double(ulong *param_1,short param_2,long param_3);
void __mpn_construct_long_double(void);
int asprintf(char **__ptr,char *__fmt,...);
__ssize_t getline(char **__lineptr,size_t *__n,FILE *__stream);
void __fxprintf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,__FILE *param_9,wchar_t *param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined8 param_14);
undefined1 *_IO_getline_info(_IO_FILE *param_1,undefined1 *param_2,ulong param_3,int param_4,int param_5,undefined4 *param_6);
void _IO_getline(void);
int fileno(FILE *__stream);
int vasprintf(char **__ptr,char *__f,__gnuc_va_list __arg);
__off64_t ftello(FILE *__stream);
long _L_lock_32(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
long _L_unlock_152(undefined8 param_1,undefined8 param_2);
void _L_unlock_200(undefined8 param_1,undefined8 param_2,undefined8 param_3);
size_t fread_unlocked(void *__ptr,size_t __size,size_t __n,FILE *__stream);
int init(EVP_PKEY_CTX *ctx);
char * __dlerror(void);
void free_key_mem(void *param_1);
bool _dlerror_run(undefined8 param_1,undefined8 param_2);
void __libc_register_dlfcn_hook(undefined8 param_1);
void __dladdr(undefined8 param_1,undefined8 param_2);
void __dladdr1(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4);
void dlinfo_doit(long param_1);
int __dlinfo(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4);
void dlmopen_doit(long *param_1);
undefined8 __dlmopen(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4);
undefined1  [16]__libc_alloc_buffer_copy_bytes(void *param_1,long param_2,void *param_3,ulong param_4);
char * strerror(int __errnum);
int strncasecmp_l(char *__s1,char *__s2,size_t __n,__locale_t __loc);
int strncasecmp(char *__s1,char *__s2,size_t __n);
ulong __strncasecmp_sse2(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
ulong __GI___strncasecmp_l(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3,long *param_4);
ulong __strncasecmp_sse42(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
ulong __strncasecmp_l_sse42(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3,long *param_4);
ulong __strncasecmp_avx(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
ulong __strncasecmp_l_avx(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3,long *param_4);
char * strsep(char **__stringp,char *__delim);
ulong __strncasecmp_ssse3(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
ulong __strncasecmp_l_ssse3(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3,long *param_4);
int __strncasecmp_l_nonascii(byte *param_1,byte *param_2,long param_3,long param_4);
int __strncasecmp_nonascii(byte *param_1,byte *param_2,long param_3);
wchar_t * wcschr(wchar_t *__wcs,wchar_t __wc);
size_t wcslen(wchar_t *__s);
undefined8 __offtime(long *param_1,long param_2,int *param_3);
long __mktime_internal(int *param_1,code *param_2,long *param_3);
time_t timelocal(tm *__tp);
void rewinddir(DIR *__dirp);
void _L_lock_15(void);
void _L_unlock_31(void);
DIR * fdopendir(int __fd);
int __GI___fxstatat64(int __ver,int __fildes,char *__filename,stat *__stat_buf,int __flag);
int gethostname(char *__name,size_t __len);
int __opensock(void);
void profil_counter(undefined8 param_1,undefined8 param_2,long param_3);
int profil(ushort *__sample_buffer,size_t __size,size_t __offset,uint __scale);
undefined4 __profile_frequency(void);
undefined8 inet_pton4(char *param_1,char *param_2,uint *param_3);
undefined8 __inet_pton_length(int param_1,char *param_2,long param_3,undefined8 *param_4);
int inet_pton(int __af,char *__cp,void *__buf);
uint if_nametoindex(char *__ifname);
void if_freenameindex(if_nameindex *__ptr);
if_nameindex * if_nameindex(void);
char * if_indextoname(uint __ifindex,char *__ifname);
void __netlink_free_handle(long param_1);
undefined8 __netlink_request(int *param_1,uint param_2);
undefined8 getifaddrs_internal(undefined8 *param_1);
undefined8 __netlink_close(void);
undefined8 __netlink_open(int *param_1);
void getifaddrs(undefined8 param_1);
void freeifaddrs(void *__ptr);
void __netlink_assert_response(uint param_1,ulong param_2);
void _dl_fixup(long *param_1,uint param_2);
code * _dl_profile_fixup(long *param_1,ulong param_2,undefined8 param_3,undefined8 param_4,undefined8 *param_5);
void _dl_call_pltexit(void);
undefined8 add_to_global(long param_1);
long _dl_open(undefined8 param_1,uint param_2,undefined8 param_3,long param_4,undefined4 param_5,undefined8 param_6,undefined8 param_7);
void _dl_show_scope(long param_1,int param_2);
void dl_open_worker(undefined8 *param_1);
undefined8 remove_slotinfo(long param_1,ulong *param_2,long param_3);
void _dl_close_worker(long param_1);
void _dl_close(long param_1);
void _dl_tlsdesc_resolve_rela_fixup(long *param_1,long *param_2);
ulong _dl_tlsdesc_resolve_hold_fixup(ulong *param_1,ulong param_2);
void _dl_unmap(long param_1);
int __gconv_open(char *param_1,char *param_2,undefined8 *param_3,undefined4 param_4);
undefined8 __gconv(long *param_1,long *param_2,ulong param_3,long *param_4,long param_5,undefined8 *param_6);
undefined8 __current_locale_name(int param_1);
long __mpn_addmul_1(ulong *param_1,ulong *param_2,long param_3,ulong param_4);
ulong _IO_helper_overflow(long param_1,uint param_2);
int vfwprintf(__FILE *__s,wchar_t *__format,__gnuc_va_list __arg);
int buffered_vfprintf(uint *param_1,wchar_t *param_2,__gnuc_va_list param_3);
ulong _L_lock_899(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
undefined4 _L_unlock_1095(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_unlock_15187(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined4 _L_lock_15211(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5);
long __parse_one_specwc(long param_1,uint param_2,uint *param_3,ulong *param_4);
void dlopen_doit(undefined8 *param_1);
undefined8 __dlopen(undefined8 param_1,undefined4 param_2,undefined8 param_3);
void dlclose_doit(long param_1);
int __dlclose(undefined8 param_1);
void dlsym_doit(undefined8 *param_1);
undefined8 __dlsym(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void dlvsym_doit(undefined8 *param_1);
undefined8 __dlvsym(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
char * strncpy(char *__dest,char *__src,size_t __n);
char * strpbrk(char *__s,char *__accept);
void __strncpy_sse2(long param_1,char *param_2,ulong param_3);
undefined1 (*) [16] __strncpy_ssse3(undefined1 (*param_1) [16],byte *param_2,ulong param_3);
undefined1 (*) [16]__strncpy_sse2_unaligned(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulong param_3);
wint_t btowc(int __c);
size_t mbsrtowcs(wchar_t *__dst,char **__src,size_t __len,mbstate_t *__ps);
wchar_t * wcschrnul(wchar_t *__s,wchar_t __wc);
long __mbsrtowcs_l(char **param_1,long *param_2,size_t param_3,undefined8 *param_4,long *param_5);
int setitimer(__itimer_which_t __which,itimerval *__new,itimerval *__old);
int bind(int __fd,sockaddr *__addr,socklen_t __len);
void openaux(long *param_1);
long _dl_build_local_scope(long *param_1,long param_2);
void _dl_map_object_deps(uint *param_1,long *param_2,uint param_3,undefined4 param_4,uint param_5);
void _dl_init(long *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4);
void _dl_sort_fini(long param_1,ulong param_2,long param_3,long param_4);
void _dl_fini(void);
undefined4 match_symbol(char *param_1,undefined8 param_2,int param_3,char *param_4,long *param_5,int param_6,int param_7);
uint _dl_check_map_versions(long *param_1,undefined4 param_2,int param_3);
byte _dl_check_all_versions(long param_1,undefined4 param_2,undefined4 param_3);
void call_dl_lookup(long *param_1);
code * do_sym(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4,uint param_5);
void _dl_vsym(undefined8 param_1,undefined8 param_2,byte *param_3,undefined8 param_4);
void _dl_sym(void);
void read_sleb128(byte *param_1,ulong *param_2);
void execute_cfa_program(byte *param_1,byte *param_2,long param_3,undefined8 *param_4);
void init_dwarf_reg_size_table(void);
undefined8 uw_frame_state_for(long param_1,long *param_2);
ulong execute_stack_op(byte *param_1,byte *param_2,long param_3,ulong param_4);
void uw_update_context_1(undefined8 *param_1,long param_2);
void uw_init_context_1(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
void uw_update_context(long param_1,long param_2);
undefined8 _Unwind_RaiseException_Phase2(undefined8 *param_1,long param_2);
undefined4 _Unwind_ForcedUnwind_Phase2(undefined8 *param_1,undefined8 param_2);
long uw_install_context_1(long param_1,long param_2);
undefined8 * _Unwind_GetGR(long param_1,int param_2);
undefined8 _Unwind_GetCFA(long param_1);
void _Unwind_SetGR(long param_1,int param_2,undefined8 param_3);
undefined8 _Unwind_GetIP(long param_1);
undefined8 _Unwind_GetIPInfo(long param_1,uint *param_2);
void _Unwind_SetIP(long param_1,undefined8 param_2);
undefined8 _Unwind_GetLanguageSpecificData(long param_1);
undefined8 _Unwind_GetRegionStart(long param_1);
undefined8 _Unwind_FindEnclosingFunction(long param_1);
undefined8 _Unwind_GetDataRelBase(long param_1);
undefined8 _Unwind_GetTextRelBase(long param_1);
long __frame_state_for(long param_1,long param_2);
void _Unwind_DebugHook(void);
undefined8 _Unwind_RaiseException(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 _Unwind_ForcedUnwind(long param_1,undefined8 param_2,undefined8 param_3);
undefined1  [16] _Unwind_Resume(long param_1,undefined8 param_2,undefined8 param_3);
undefined1  [16] _Unwind_Resume_or_Rethrow(long param_1,undefined8 param_2,undefined8 param_3);
void _Unwind_DeleteException(long param_1);
undefined8 _Unwind_Backtrace(code *param_1,undefined8 param_2);
void read_sleb128(byte *param_1,ulong *param_2);
int fde_unencoded_compare(undefined8 param_1,long param_2,long param_3);
void frame_downheap(undefined8 param_1,code *param_2,long param_3,int param_4,int param_5);
void frame_heapsort(undefined8 param_1,undefined8 param_2,long param_3);
undefined8 size_of_encoded_value(byte param_1);
uint * read_encoded_value_with_base(byte param_1,uint *param_2,uint *param_3,undefined8 *param_4);
byte get_cie_encoding(long param_1);
undefined8 base_from_object.isra.3(byte param_1,undefined8 *param_2,undefined8 *param_3);
int fde_single_encoding_compare(long param_1,long param_2,long param_3);
uint * linear_search_fdes(long param_1,uint *param_2,long param_3);
int fde_mixed_encoding_compare(long param_1,long param_2,long param_3);
long classify_object_over_fdes(ulong *param_1,uint *param_2);
void add_fdes(long param_1,long *param_2,uint *param_3);
long search_object(ulong *param_1,ulong param_2);
undefined8 base_from_cb_data.isra.4(byte param_1,undefined8 *param_2,undefined8 *param_3);
undefined8 _Unwind_IteratePhdrCallback(ulong *param_1,ulong param_2,ulong *param_3);
void __register_frame_info_bases(int *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4);
void __register_frame_info(undefined8 param_1,undefined8 param_2);
void __register_frame(int *param_1);
void __register_frame_info_table_bases(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4);
void __register_frame_info_table(undefined8 param_1,undefined8 param_2);
void __register_frame_table(undefined8 param_1);
long __deregister_frame_info_bases(int *param_1);
long __deregister_frame_info(int *param_1);
void __deregister_frame(int *param_1);
long _Unwind_Find_FDE(ulong param_1,ulong *param_2);
undefined8 base_of_encoded_value(byte param_1,undefined8 param_2);
uint * read_encoded_value_with_base(byte param_1,uint *param_2,uint *param_3,undefined8 *param_4);
undefined8 __gcc_personality_v0(int param_1,uint param_2,undefined8 param_3,undefined8 param_4,long param_5);
int __dl_iterate_phdr(code *param_1,undefined8 param_2);
ulong dl_iterate_phdr(code *param_1,undefined8 param_2);
void buffer_free(void);
void free_mem(void);
void _L_lock_7(void);
void _L_unlock_21(void);
void hst_map_free(void);
void free_derivation(void *param_1);
void free_modules_db(void *param_1);
void free_mem(void);
void free_mem(void);
void free_mem(void);
void do_release_all(void *param_1);
void free_mem(void);
void _nl_locale_subfreeres(void);
void _nl_archive_subfreeres(void);
void _nl_finddomain_subfreeres(void);
void _nl_unload_domain(undefined8 *param_1);
void free_mem(void);
void free_mem(void);
void free_mem(void);
void free_mem(void);
void free_defconfig(void);
undefined8 free_slotinfo(long *param_1);
void free_mem(void);
void free_mem(void);
long arena_thread_freeres(void);
void _L_lock_18(void);
void _L_unlock_34(void);
void __libc_thread_freeres(void);
void res_thread_freeres(void);
void freeres(void);
void _fini(void);

