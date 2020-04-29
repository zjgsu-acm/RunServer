//
// File:   okcalls.h
// Author: sempr
// refacted by sakeven
/*
 * Copyright 2008 sempr <iamsempr@gmail.com>
 *
 * Refacted and modified by sakeven<jc5930@sina.cn>
 * Bug report email jc5930@sina.cn
 *
 *
 * This file is part of RunServer.
 *
 * RunServer is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * RunServer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RunServer. if not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/syscall.h>
#define HOJ_MAX_LIMIT -1
#ifdef __i386


int LANG_JV[256]={3,4,5,6,10,11,13,33,39,45,75,78,85,91,93,102,116,120,122,125,140,141,174,175,183,191,192,195,196,197,201,218,220,224,240,243,252,258,265,266,295,311,0};

int LANG_JC[256]={HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,0};

int LANG_CV[256]={8,SYS_time,SYS_read, SYS_uname, SYS_write,  SYS_execve, SYS_access, SYS_brk, SYS_munmap, SYS_mprotect, SYS_mmap2, SYS_fstat64, SYS_set_thread_area,SYS_readlink, 252,0};

int LANG_CC[256]={HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT,1, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,  2,HOJ_MAX_LIMIT,0};

//python
int LANG_PV[256]={3,4,5,6,11,20,22,33,41,45,54,85,91,116,122,125,140,174,175,183,
		191,192,195,196,197,199,200,201,202,220,221,243,252,258,265,295,
		311,13,41,91,102,186,221,240,295,355,0};

#else

int LANG_JV[256] = { 0,2,3,4,5,9,10,11,12,13,14,21,56,59,89,97,158,202,218,231,273,257, 61, 22, 6, 33, 8, 13, 16, 111, 110, 39, 79, SYS_fcntl, SYS_getdents64, SYS_getrlimit, SYS_rt_sigprocmask, SYS_futex, SYS_read, SYS_mmap, SYS_stat, SYS_open, SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_readlink, SYS_munmap, SYS_close, SYS_uname, SYS_clone, SYS_uname, SYS_mprotect, SYS_rt_sigaction, SYS_getrlimit, SYS_fstat, SYS_getuid, SYS_getgid, SYS_geteuid, SYS_getegid, SYS_set_thread_area, SYS_set_tid_address, SYS_set_robust_list, SYS_exit_group, 158, 0 };
  
int LANG_JC[256]={HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,0};

int LANG_CV[256] = {0,1,5,9,11,12,21,59,63,89,158,231, 8, SYS_time, SYS_read, SYS_uname, SYS_write, SYS_open, SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_munmap, SYS_mprotect, SYS_mmap, SYS_fstat, SYS_set_thread_area, 252, SYS_arch_prctl, 231, 0 };

int LANG_CC[256]={HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT,  HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, HOJ_MAX_LIMIT, 2,HOJ_MAX_LIMIT,HOJ_MAX_LIMIT,0};

//python
int LANG_PV[256] = {0,2,3,4,5,6,8,9,10,11,12,13,14,16,17,21,32,59,72,78,79,89,97,99,102,104,107,108,131,158,217,218,228,231,272,273,318,39,99,302,99,32,72,131,1,202,257,41, 42, 146, SYS_mremap, 158, 117, 60, 39, 102, 191,
		SYS_access, SYS_arch_prctl, SYS_brk, SYS_close, SYS_execve,
		SYS_exit_group, SYS_fcntl, SYS_fstat, SYS_futex, SYS_getcwd,
		SYS_getdents, SYS_getegid, SYS_geteuid, SYS_getgid, SYS_getrlimit,
		SYS_getuid, SYS_ioctl, SYS_lseek, SYS_lstat, SYS_mmap, SYS_mprotect,
		SYS_munmap, SYS_open, SYS_read, SYS_readlink, SYS_rt_sigaction,
		SYS_rt_sigprocmask, SYS_set_robust_list, SYS_set_tid_address, SYS_stat,
		SYS_write, 0 };
#endif
