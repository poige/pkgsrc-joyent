$NetBSD$

--- hotspot/src/os_cpu/solaris_x86/vm/threadLS_solaris_x86.hpp.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/threadLS_solaris_x86.hpp
@@ -65,7 +65,10 @@ public:
     __asm__ __volatile__ ("movq %%fs:0, %0" : "=r"(rv));
     return rv;
 #else
-    return gs_thread();
+    uintptr_t rv;
+    __asm__ __volatile__ ("movl %%gs:0, %0" : "=r"(rv));
+    return rv;
+//    return gs_thread();
 #endif // AMD64
 #else  //_GNU_SOURCE
     return _raw_thread_id();
