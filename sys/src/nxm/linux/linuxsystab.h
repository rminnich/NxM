typedef void Syscall(Ar0*, va_list);

Syscall linuxuname;
Syscall	linuxbrk;
Syscall linuxopen;
Syscall linuxclose;
Syscall syssegbrk;
Syscall linuxwritev;
Syscall linuxsocketcall;
Syscall linuxgeteuid;
Syscall linuxmmap;
Syscall linuxexit;
Syscall linuxsettid;
Syscall sigaction;
Syscall rt_sigprocmask;
Syscall fstat64;
Syscall returnok;
Syscall futex;
Syscall linuxgetpersonality;
Syscall linuxr2c;
Syscall linuxc2r;
Syscall linuxprocid;
Syscall linuxranks2coords;
Syscall linuxmprotect;
Syscall linuxclone;
Syscall gasm;
Syscall linuxcga;
Syscall getrusage;
Syscall arch_prctl;
extern Syscall sys_write;
extern Syscall sys_read;
extern Syscall sysopen;
extern Syscall sysclose;
extern Syscall syspread;
Syscall sysnoted;

struct syscall {
	char*	n;
	Syscall*f;
	int narg;
	Ar0	r;
};

struct syscall linuxsystab[] = {
	[0]	{"read", sys_read, 3, {.i = 0}},
	[1]		{"write", sys_write, 3, {.p = (uintptr)-1}},
	[2]		{"linuxopen", linuxopen, 2, {.p = (uintptr)-1}},
	[3] 		{"linuxclose", sysclose, 1, {.p = (uintptr)-1}},
	[102]		{"getuid", linuxgeteuid, 0, {.p = (uintptr)-1}},
	[12]		{"linuxbrk", linuxbrk, 1, {.p = (uintptr)-1}},
	[104]		{"getgid", linuxgeteuid, 0, {.p = (uintptr)-1}},
	[107]		{"geteuid", linuxgeteuid, 0, {.p = (uintptr)-1}},
	[108]		{"getegid", linuxgeteuid, 0, {.p = (uintptr)-1}},
	[98]	{"getrusage", getrusage, 1, {.i = 0}},
	[9]		{"mmap", linuxmmap, 5, {.p = 0xfffffffffffff001ULL}},
	[63]	{"linuxuname", linuxuname, 1, {.p = (uintptr)-1}},
	[13]	{"sigaction", sigaction, 2, {.p = (uintptr)-1}},
	[14]	{"rt_sigprocmask", rt_sigprocmask, 4, {.l = -1}},
	[60]	{"linuxexit", linuxexit, 1, {.p = (uintptr)-1}},
	[197]	{"fstat64", fstat64, 1, {.p = (uintptr)-1}},
	[5] 	{"fstat", fstat64, 1, {.p = (void *)-1}},
	[231]	{"exit_group", linuxexit, 1, {.p = (void *)-1}},
	[17]	{"pread64", syspread, 5, {.i = 0}},
//	[102]	{"socketcall", linuxsocketcall, 1, {.i = 0}},
	[56]	{"clone", linuxclone, 1, {.i = 0}},
	[10]	{"mprotect", linuxmprotect, 1, {.i = 0}},
	[20]	{"writev", linuxwritev, 1, {.i = 0}},
//	[197]	{"fstat64", fstat64, 1, {.p = (uintptr)-1}},
//	[221]	{"futex", futex, 1, {.i = 0}},
	[158] {"arch_prctl", arch_prctl, 2, {.p = (void *)-1}},

	[4] {"stat", nil, 1, {.p = (void *)-1}},
//	[5] {"fstat", nil, 1, {.p = (void *)-1}},
	[6] {"lstat", nil, 1, {.p = (void *)-1}},
	[7] {"poll", nil, 1, {.p = (void *)-1}},
	[8] {"lseek", nil, 1, {.p = (void *)-1}},

	[11] {"munmap", nil, 1, {.p = (void *)-1}},

	[15] {"rt_sigreturn", nil, 1, {.p = (void *)-1}},
	[16] {"ioctl", nil, 1, {.p = (void *)-1}},

	[18] {"pwrite64", nil, 1, {.p = (void *)-1}},
	[19] {"readv", nil, 1, {.p = (void *)-1}},

	[21] {"access", nil, 1, {.p = (void *)-1}},
	[22] {"pipe", nil, 1, {.p = (void *)-1}},
	[23] {"select", nil, 1, {.p = (void *)-1}},
	[24] {"sched_yield", nil, 1, {.p = (void *)-1}},
	[25] {"mremap", nil, 1, {.p = (void *)-1}},
	[26] {"msync", nil, 1, {.p = (void *)-1}},
	[27] {"mincore", nil, 1, {.p = (void *)-1}},
	[28] {"madvise", nil, 1, {.p = (void *)-1}},
	[29] {"shmget", nil, 1, {.p = (void *)-1}},
	[30] {"shmat", nil, 1, {.p = (void *)-1}},
	[31] {"shmctl", nil, 1, {.p = (void *)-1}},
	[32] {"dup", nil, 1, {.p = (void *)-1}},
	[33] {"dup2", nil, 1, {.p = (void *)-1}},
	[34] {"pause", nil, 1, {.p = (void *)-1}},
	[35] {"nanosleep", nil, 1, {.p = (void *)-1}},
	[36] {"getitimer", nil, 1, {.p = (void *)-1}},
	[37] {"alarm", nil, 1, {.p = (void *)-1}},
	[38] {"setitimer", nil, 1, {.p = (void *)-1}},
	[39] {"getpid", nil, 1, {.p = (void *)-1}},
	[40] {"sendfile", nil, 1, {.p = (void *)-1}},
	[41] {"socket", nil, 1, {.p = (void *)-1}},
	[42] {"connect", nil, 1, {.p = (void *)-1}},
	[43] {"accept", nil, 1, {.p = (void *)-1}},
	[44] {"sendto", nil, 1, {.p = (void *)-1}},
	[45] {"recvfrom", nil, 1, {.p = (void *)-1}},
	[46] {"sendmsg", nil, 1, {.p = (void *)-1}},
	[47] {"recvmsg", nil, 1, {.p = (void *)-1}},
	[48] {"shutdown", nil, 1, {.p = (void *)-1}},
	[49] {"bind", nil, 1, {.p = (void *)-1}},
	[50] {"listen", nil, 1, {.p = (void *)-1}},
	[51] {"getsockname", nil, 1, {.p = (void *)-1}},
	[52] {"getpeername", nil, 1, {.p = (void *)-1}},
	[53] {"socketpair", nil, 1, {.p = (void *)-1}},
	[54] {"setsockopt", nil, 1, {.p = (void *)-1}},
	[55] {"getsockopt", nil, 1, {.p = (void *)-1}},

	[57] {"fork", nil, 1, {.p = (void *)-1}},
	[58] {"vfork", nil, 1, {.p = (void *)-1}},
	[59] {"execve", nil, 1, {.p = (void *)-1}},

	[61] {"wait4", nil, 1, {.p = (void *)-1}},
	[62] {"kill", nil, 1, {.p = (void *)-1}},

	[64] {"semget", nil, 1, {.p = (void *)-1}},
	[65] {"semop", nil, 1, {.p = (void *)-1}},
	[66] {"semctl", nil, 1, {.p = (void *)-1}},
	[67] {"shmdt", nil, 1, {.p = (void *)-1}},
	[68] {"msgget", nil, 1, {.p = (void *)-1}},
	[69] {"msgsnd", nil, 1, {.p = (void *)-1}},
	[70] {"msgrcv", nil, 1, {.p = (void *)-1}},
	[71] {"msgctl", nil, 1, {.p = (void *)-1}},
	[72] {"fcntl", nil, 1, {.p = (void *)-1}},
	[73] {"flock", nil, 1, {.p = (void *)-1}},
	[74] {"fsync", nil, 1, {.p = (void *)-1}},
	[75] {"fdatasync", nil, 1, {.p = (void *)-1}},
	[76] {"truncate", nil, 1, {.p = (void *)-1}},
	[77] {"ftruncate", nil, 1, {.p = (void *)-1}},
	[78] {"getdents", nil, 1, {.p = (void *)-1}},
	[79] {"getcwd", nil, 1, {.p = (void *)-1}},
	[80] {"chdir", nil, 1, {.p = (void *)-1}},
	[81] {"fchdir", nil, 1, {.p = (void *)-1}},
	[82] {"rename", nil, 1, {.p = (void *)-1}},
	[83] {"mkdir", nil, 1, {.p = (void *)-1}},
	[84] {"rmdir", nil, 1, {.p = (void *)-1}},
	[85] {"creat", nil, 1, {.p = (void *)-1}},
	[86] {"link", nil, 1, {.p = (void *)-1}},
	[87] {"unlink", nil, 1, {.p = (void *)-1}},
	[88] {"symlink", nil, 1, {.p = (void *)-1}},
	[89] {"readlink", nil, 1, {.p = (void *)-1}},
	[90] {"chmod", nil, 1, {.p = (void *)-1}},
	[91] {"fchmod", nil, 1, {.p = (void *)-1}},
	[92] {"chown", nil, 1, {.p = (void *)-1}},
	[93] {"fchown", nil, 1, {.p = (void *)-1}},
	[94] {"lchown", nil, 1, {.p = (void *)-1}},
	[95] {"umask", nil, 1, {.p = (void *)-1}},
	[96] {"gettimeofday", nil, 1, {.p = (void *)-1}},
	[97] {"getrlimit", nil, 1, {.p = (void *)-1}},

	[99] {"sysinfo", nil, 1, {.p = (void *)-1}},
	[100] {"times", nil, 1, {.p = (void *)-1}},
	[101] {"ptrace", nil, 1, {.p = (void *)-1}},

	[103] {"syslog", nil, 1, {.p = (void *)-1}},

	[105] {"setuid", nil, 1, {.p = (void *)-1}},
	[106] {"setgid", nil, 1, {.p = (void *)-1}},

	[109] {"setpgid", nil, 1, {.p = (void *)-1}},
	[110] {"getppid", nil, 1, {.p = (void *)-1}},
	[111] {"getpgrp", nil, 1, {.p = (void *)-1}},
	[112] {"setsid", nil, 1, {.p = (void *)-1}},
	[113] {"setreuid", nil, 1, {.p = (void *)-1}},
	[114] {"setregid", nil, 1, {.p = (void *)-1}},
	[115] {"getgroups", nil, 1, {.p = (void *)-1}},
	[116] {"setgroups", nil, 1, {.p = (void *)-1}},
	[117] {"setresuid", nil, 1, {.p = (void *)-1}},
	[118] {"getresuid", nil, 1, {.p = (void *)-1}},
	[119] {"setresgid", nil, 1, {.p = (void *)-1}},
	[120] {"getresgid", nil, 1, {.p = (void *)-1}},
	[121] {"getpgid", nil, 1, {.p = (void *)-1}},
	[122] {"setfsuid", nil, 1, {.p = (void *)-1}},
	[123] {"setfsgid", nil, 1, {.p = (void *)-1}},
	[124] {"getsid", nil, 1, {.p = (void *)-1}},
	[125] {"capget", nil, 1, {.p = (void *)-1}},
	[126] {"capset", nil, 1, {.p = (void *)-1}},
	[127] {"rt_sigpending", nil, 1, {.p = (void *)-1}},
	[128] {"rt_sigtimedwait", nil, 1, {.p = (void *)-1}},
	[129] {"rt_sigqueueinfo", nil, 1, {.p = (void *)-1}},
	[130] {"rt_sigsuspend", nil, 1, {.p = (void *)-1}},
	[131] {"sigaltstack", nil, 1, {.p = (void *)-1}},
	[132] {"utime", nil, 1, {.p = (void *)-1}},
	[133] {"mknod", nil, 1, {.p = (void *)-1}},
	[134] {"uselib", nil, 1, {.p = (void *)-1}},
	[135] {"personality", nil, 1, {.p = (void *)-1}},
	[136] {"ustat", nil, 1, {.p = (void *)-1}},
	[137] {"statfs", nil, 1, {.p = (void *)-1}},
	[138] {"fstatfs", nil, 1, {.p = (void *)-1}},
	[139] {"sysfs", nil, 1, {.p = (void *)-1}},
	[140] {"getpriority", nil, 1, {.p = (void *)-1}},
	[141] {"setpriority", nil, 1, {.p = (void *)-1}},
	[142] {"sched_setparam", nil, 1, {.p = (void *)-1}},
	[143] {"sched_getparam", nil, 1, {.p = (void *)-1}},
	[144] {"sched_setscheduler", nil, 1, {.p = (void *)-1}},
	[145] {"sched_getscheduler", nil, 1, {.p = (void *)-1}},
	[146] {"sched_get_priority_max", nil, 1, {.p = (void *)-1}},
	[147] {"sched_get_priority_min", nil, 1, {.p = (void *)-1}},
	[148] {"sched_rr_get_interval", nil, 1, {.p = (void *)-1}},
	[149] {"mlock", nil, 1, {.p = (void *)-1}},
	[150] {"munlock", nil, 1, {.p = (void *)-1}},
	[151] {"mlockall", nil, 1, {.p = (void *)-1}},
	[152] {"munlockall", nil, 1, {.p = (void *)-1}},
	[153] {"vhangup", nil, 1, {.p = (void *)-1}},
	[154] {"modify_ldt", nil, 1, {.p = (void *)-1}},
	[155] {"pivot_root", nil, 1, {.p = (void *)-1}},
	[156] {"_sysctl", nil, 1, {.p = (void *)-1}},
	[157] {"prctl", nil, 1, {.p = (void *)-1}},

	[159] {"adjtimex", nil, 1, {.p = (void *)-1}},
	[160] {"setrlimit", nil, 1, {.p = (void *)-1}},
	[161] {"chroot", nil, 1, {.p = (void *)-1}},
	[162] {"sync", nil, 1, {.p = (void *)-1}},
	[163] {"acct", nil, 1, {.p = (void *)-1}},
	[164] {"settimeofday", nil, 1, {.p = (void *)-1}},
	[165] {"mount", nil, 1, {.p = (void *)-1}},
	[166] {"umount2", nil, 1, {.p = (void *)-1}},
	[167] {"swapon", nil, 1, {.p = (void *)-1}},
	[168] {"swapoff", nil, 1, {.p = (void *)-1}},
	[169] {"reboot", nil, 1, {.p = (void *)-1}},
	[170] {"sethostname", nil, 1, {.p = (void *)-1}},
	[171] {"setdomainname", nil, 1, {.p = (void *)-1}},
	[172] {"iopl", nil, 1, {.p = (void *)-1}},
	[173] {"ioperm", nil, 1, {.p = (void *)-1}},
	[174] {"create_module", nil, 1, {.p = (void *)-1}},
	[175] {"init_module", nil, 1, {.p = (void *)-1}},
	[176] {"delete_module", nil, 1, {.p = (void *)-1}},
	[177] {"get_kernel_syms", nil, 1, {.p = (void *)-1}},
	[178] {"query_module", nil, 1, {.p = (void *)-1}},
	[179] {"quotactl", nil, 1, {.p = (void *)-1}},
	[180] {"nfsservctl", nil, 1, {.p = (void *)-1}},
	[181] {"getpmsg", nil, 1, {.p = (void *)-1}},
	[182] {"putpmsg", nil, 1, {.p = (void *)-1}},
	[183] {"afs_syscall", nil, 1, {.p = (void *)-1}},
	[184] {"tuxcall", nil, 1, {.p = (void *)-1}},
	[185] {"security", nil, 1, {.p = (void *)-1}},
	[186] {"gettid", nil, 1, {.p = (void *)-1}},
	[187] {"readahead", nil, 1, {.p = (void *)-1}},
	[188] {"setxattr", nil, 1, {.p = (void *)-1}},
	[189] {"lsetxattr", nil, 1, {.p = (void *)-1}},
	[190] {"fsetxattr", nil, 1, {.p = (void *)-1}},
	[191] {"getxattr", nil, 1, {.p = (void *)-1}},
	[192] {"lgetxattr", nil, 1, {.p = (void *)-1}},
	[193] {"fgetxattr", nil, 1, {.p = (void *)-1}},
	[194] {"listxattr", nil, 1, {.p = (void *)-1}},
	[195] {"llistxattr", nil, 1, {.p = (void *)-1}},
	[196] {"flistxattr", nil, 1, {.p = (void *)-1}},
//	[197] {"removexattr", nil, 1, {.p = (void *)-1}},
	[198] {"lremovexattr", nil, 1, {.p = (void *)-1}},
	[199] {"fremovexattr", nil, 1, {.p = (void *)-1}},
	[200] {"tkill", nil, 1, {.p = (void *)-1}},
	[201] {"time", nil, 1, {.p = (void *)-1}},
	[202] {"futex", nil, 1, {.p = (void *)-1}},
	[203] {"sched_setaffinity", nil, 1, {.p = (void *)-1}},
	[204] {"sched_getaffinity", nil, 1, {.p = (void *)-1}},
	[205] {"set_thread_area", nil, 1, {.p = (void *)-1}},
	[206] {"io_setup", nil, 1, {.p = (void *)-1}},
	[207] {"io_destroy", nil, 1, {.p = (void *)-1}},
	[208] {"io_getevents", nil, 1, {.p = (void *)-1}},
	[209] {"io_submit", nil, 1, {.p = (void *)-1}},
	[210] {"io_cancel", nil, 1, {.p = (void *)-1}},
	[211] {"get_thread_area", nil, 1, {.p = (void *)-1}},
	[212] {"lookup_dcookie", nil, 1, {.p = (void *)-1}},
	[213] {"epoll_create", nil, 1, {.p = (void *)-1}},
	[214] {"epoll_ctl_old", nil, 1, {.p = (void *)-1}},
	[215] {"epoll_wait_old", nil, 1, {.p = (void *)-1}},
	[216] {"remap_file_pages", nil, 1, {.p = (void *)-1}},
	[217] {"getdents64", nil, 1, {.p = (void *)-1}},
	[218] {"set_tid_address", nil, 1, {.p = (void *)-1}},
	[219] {"restart_syscall", nil, 1, {.p = (void *)-1}},
	[220] {"semtimedop", nil, 1, {.p = (void *)-1}},
	[221] {"fadvise64", nil, 1, {.p = (void *)-1}},
	[222] {"timer_create", nil, 1, {.p = (void *)-1}},
	[223] {"timer_settime", nil, 1, {.p = (void *)-1}},
	[224] {"timer_gettime", nil, 1, {.p = (void *)-1}},
	[225] {"timer_getoverrun", nil, 1, {.p = (void *)-1}},
	[226] {"timer_delete", nil, 1, {.p = (void *)-1}},
	[227] {"clock_settime", nil, 1, {.p = (void *)-1}},
	[228] {"clock_gettime", nil, 1, {.p = (void *)-1}},
	[229] {"clock_getres", nil, 1, {.p = (void *)-1}},
	[230] {"clock_nanosleep", nil, 1, {.p = (void *)-1}},
//	[231] {"exit_group", nil, 1, {.p = (void *)-1}},
	[232] {"epoll_wait", nil, 1, {.p = (void *)-1}},
	[233] {"epoll_ctl", nil, 1, {.p = (void *)-1}},
	[234] {"tgkill", nil, 1, {.p = (void *)-1}},
	[235] {"utimes", nil, 1, {.p = (void *)-1}},
	[236] {"vserver", nil, 1, {.p = (void *)-1}},
	[237] {"mbind", nil, 1, {.p = (void *)-1}},
	[238] {"set_mempolicy", nil, 1, {.p = (void *)-1}},
	[239] {"get_mempolicy", nil, 1, {.p = (void *)-1}},
	[240] {"mq_open", nil, 1, {.p = (void *)-1}},
	[241] {"mq_unlink", nil, 1, {.p = (void *)-1}},
	[242] {"mq_timedsend", nil, 1, {.p = (void *)-1}},
	[243] {"mq_timedreceive", nil, 1, {.p = (void *)-1}},
	[244] {"mq_notify", nil, 1, {.p = (void *)-1}},
	[245] {"mq_getsetattr", nil, 1, {.p = (void *)-1}},
	[246] {"kexec_load", nil, 1, {.p = (void *)-1}},
	[247] {"waitid", nil, 1, {.p = (void *)-1}},
	[248] {"add_key", nil, 1, {.p = (void *)-1}},
	[249] {"request_key", nil, 1, {.p = (void *)-1}},
	[250] {"keyctl", nil, 1, {.p = (void *)-1}},
	[251] {"ioprio_set", nil, 1, {.p = (void *)-1}},
	[252] {"ioprio_get", nil, 1, {.p = (void *)-1}},
	[253] {"inotify_init", nil, 1, {.p = (void *)-1}},
	[254] {"inotify_add_watch", nil, 1, {.p = (void *)-1}},
	[255] {"inotify_rm_watch", nil, 1, {.p = (void *)-1}},
	[256] {"migrate_pages", nil, 1, {.p = (void *)-1}},
	[257] {"openat", nil, 1, {.p = (void *)-1}},
	[258] {"mkdirat", nil, 1, {.p = (void *)-1}},
	[259] {"mknodat", nil, 1, {.p = (void *)-1}},
	[260] {"fchownat", nil, 1, {.p = (void *)-1}},
	[261] {"futimesat", nil, 1, {.p = (void *)-1}},
	[262] {"newfstatat", nil, 1, {.p = (void *)-1}},
	[263] {"unlinkat", nil, 1, {.p = (void *)-1}},
	[264] {"renameat", nil, 1, {.p = (void *)-1}},
	[265] {"linkat", nil, 1, {.p = (void *)-1}},
	[266] {"symlinkat", nil, 1, {.p = (void *)-1}},
	[267] {"readlinkat", nil, 1, {.p = (void *)-1}},
	[268] {"fchmodat", nil, 1, {.p = (void *)-1}},
	[269] {"faccessat", nil, 1, {.p = (void *)-1}},
	[270] {"pselect6", nil, 1, {.p = (void *)-1}},
	[271] {"ppoll", nil, 1, {.p = (void *)-1}},
	[272] {"unshare", nil, 1, {.p = (void *)-1}},
	[273] {"set_robust_list", nil, 1, {.p = (void *)-1}},
	[274] {"get_robust_list", nil, 1, {.p = (void *)-1}},
	[275] {"splice", nil, 1, {.p = (void *)-1}},
	[276] {"tee", nil, 1, {.p = (void *)-1}},
	[277] {"sync_file_range", nil, 1, {.p = (void *)-1}},
	[278] {"vmsplice", nil, 1, {.p = (void *)-1}},
	[279] {"move_pages", nil, 1, {.p = (void *)-1}},
	[280] {"utimensat", nil, 1, {.p = (void *)-1}},
	[281] {"epoll_pwait", nil, 1, {.p = (void *)-1}},
	[282] {"signalfd", nil, 1, {.p = (void *)-1}},
	[283] {"timerfd_create", nil, 1, {.p = (void *)-1}},
	[284] {"eventfd", nil, 1, {.p = (void *)-1}},
	[285] {"fallocate", nil, 1, {.p = (void *)-1}},
	[286] {"timerfd_settime", nil, 1, {.p = (void *)-1}},
	[287] {"timerfd_gettime", nil, 1, {.p = (void *)-1}},
	[288] {"accept4", nil, 1, {.p = (void *)-1}},
	[289] {"signalfd4", nil, 1, {.p = (void *)-1}},
	[290] {"eventfd2", nil, 1, {.p = (void *)-1}},
	[291] {"epoll_create1", nil, 1, {.p = (void *)-1}},
	[292] {"dup3", nil, 1, {.p = (void *)-1}},
	[293] {"pipe2", nil, 1, {.p = (void *)-1}},
	[294] {"inotify_init1", nil, 1, {.p = (void *)-1}},
	[295] {"preadv", nil, 1, {.p = (void *)-1}},
	[296] {"pwritev", nil, 1, {.p = (void *)-1}},
	[297] {"rt_tgsigqueueinfo", nil, 1, {.p = (void *)-1}},
	[298] {"perf_event_open", nil, 1, {.p = (void *)-1}},
	[299] {"recvmmsg", nil, 1, {.p = (void *)-1}},
	/* they won't get here for at least a year */
	[1024] {"noted", sysnoted, 1, {.p = (void *)-1}},

};

int nlinuxsyscall = nelem(linuxsystab);

