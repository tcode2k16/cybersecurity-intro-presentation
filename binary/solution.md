The objective is to patch the binary and turn `if (x == 2)` to `if (x == 1)`.

Here is the process:
```
❯ ./main
welcome to the impossible program!
See it's impossible!
❯ r2 main
syntax error: error in error handling
syntax error: error in error handling
syntax error: error in error handling
r_config_set: variable 'asm.cmtright' not found
 -- radare2 0.9.7 is so old, my grandfarther was using it with his enigma in WWII
[0x100000dc0]> aaaa
[x] Analyze all flags starting with sym. and entry0 (aa)
[x] Analyze function calls (aac)
[x] Analyze len bytes of instructions for references (aar)
[x] Emulate code to find computed references (aae)
[x] Analyze consecutive function (aat)
[x] Constructing a function name for fcn.* and sym.func.* functions (aan)
[x] Type matching analysis for all functions (afta)
[0x100000dc0]> afl
0x100000dc0    9 271          entry0
0x100000ed0    1 6            sym.imp.__stack_chk_fail
0x100000ed6    1 6            sym.imp.printf
0x100000edc    1 6            sym.imp.strlen
[0x100000dc0]> s entry0
[0x100000dc0]> pdf
            ;-- section.0.__TEXT.__text:
            ;-- _main:
            ;-- func.100000dc0:
            ;-- rip:
┌ (fcn) entry0 271
│   entry0 (int arg_20h);
│           ; var int local_48h @ rbp-0x48
│           ; var int local_44h @ rbp-0x44
│           ; var int local_40h @ rbp-0x40
│           ; var int local_34h @ rbp-0x34
│           ; var int local_30h @ rbp-0x30
│           ; var int local_2ch @ rbp-0x2c
│           ; var int local_28h @ rbp-0x28
│           ; var int local_24h @ rbp-0x24
│           ; var int local_20h @ rbp-0x20
│           ; var int local_18h @ rbp-0x18
│           ; var int local_10h @ rbp-0x10
│           ; var int local_8h @ rbp-0x8
│           ; arg int arg_20h @ rbp+0x20
│           ; CALL XREF from 0x100000dc0 (entry0)
│           0x100000dc0      55             push rbp                   ; [00] -r-x section size 271 named 0.__TEXT.__text
│           0x100000dc1      4889e5         rbp = rsp
│           0x100000dc4      4883ec50       rsp -= 0x50                ; 'P'
│           0x100000dc8      488d3d510100.  rdi = str.welcome_to_the_impossible_program ; section.3.__TEXT.__cstring ; 0x100000f20 ; "welcome to the impossible program!\n" ; const char *format
│           0x100000dcf      488b052a0200.  rax = qword [reloc.__stack_chk_guard] ; [0x100001000:8]=0
│           0x100000dd6      488b00         rax = qword [rax]
│           0x100000dd9      488945f8       qword [local_8h] = rax
│           0x100000ddd      c745dc000000.  dword [local_24h] = 0
│           0x100000de4      c745d8000000.  dword [local_28h] = 0
│           0x100000deb      b000           al = 0
│           0x100000ded      e8e4000000     sym.imp.printf ()          ; int printf(const char *format)
│           0x100000df2      8b4dd8         ecx = dword [local_28h]
│           0x100000df5      83c101         ecx += 1
│           0x100000df8      894dd8         dword [local_28h] = ecx
│           0x100000dfb      837dd802       var = dword [local_28h] - 2 ; [0x2:4]=-1 ; 2
│           0x100000dff      8945d0         dword [local_30h] = eax
│       ┌─< 0x100000e02      0f8595000000   if (var) goto 0x100000e9d
│       │   0x100000e08      488d3d350100.  rdi = str.Congratulation_for_achieving_the_impossible ; 0x100000f44 ; "Congratulation for achieving the impossible!\n" ; const char *format
│       │   0x100000e0f      b000           al = 0
│       │   0x100000e11      e8c0000000     sym.imp.printf ()          ; int printf(const char *format)
│       │   0x100000e16      488b3d630100.  rdi = qword str.i_lqlcxy_UhcdkxsUzk_ibw ; [0x100000f80:8]=0x7978636c716c7e69 ; "i~lqlcxy~UhcdkxsUzk~ibw"
│       │   0x100000e1d      48897de0       qword [local_20h] = rdi
│       │   0x100000e21      488b3d600100.  rdi = qword [0x100000f88]  ; [0x100000f88:8]=0x73786b646368557e ; 4294971272
│       │   0x100000e28      48897de8       qword [local_18h] = rdi
│       │   0x100000e2c      488b3d5d0100.  rdi = qword [0x100000f90]  ; [0x100000f90:8]=0x7762697e6b7a55 ; 4294971280
│       │   0x100000e33      48897df0       qword [local_10h] = rdi
│       │   0x100000e37      c745d4000000.  dword [local_2ch] = 0
│       │   0x100000e3e      8945cc         dword [local_34h] = eax
│       │   ; CODE XREF from 0x100000e7e (entry0)
│      ┌──> 0x100000e41      488d7de0       rdi = [local_20h]          ; const char *s
│      ⁝│   0x100000e45      486345d4       rax = dword [local_2ch]
│      ⁝│   0x100000e49      488945c0       qword [local_40h] = rax
│      ⁝│   0x100000e4d      e88a000000     sym.imp.strlen ()          ; size_t strlen(const char *s)
│      ⁝│   0x100000e52      488b7dc0       rdi = qword [local_40h]
│      ⁝│   0x100000e56      4839c7         var = rdi - rax
│     ┌───< 0x100000e59      0f8324000000   jae 0x100000e83
│     │⁝│   0x100000e5f      486345d4       rax = dword [local_2ch]
│     │⁝│   0x100000e63      0fbe4c05e0     ecx = byte [rbp + rax - 0x20]
│     │⁝│   0x100000e68      83f10a         ecx ^= 0xa
│     │⁝│   0x100000e6b      88ca           dl = cl
│     │⁝│   0x100000e6d      486345d4       rax = dword [local_2ch]
│     │⁝│   0x100000e71      885405e0       byte [rbp + rax - 0x20] = dl
│     │⁝│   0x100000e75      8b45d4         eax = dword [local_2ch]
│     │⁝│   0x100000e78      83c001         eax += 1
│     │⁝│   0x100000e7b      8945d4         dword [local_2ch] = eax
│     │└──< 0x100000e7e      e9beffffff     goto 0x100000e41
│     │ │   ; CODE XREF from 0x100000e59 (entry0)
│     └───> 0x100000e83      488d3d0e0100.  rdi = str.flag:__s         ; 0x100000f98 ; "flag: %s\n" ; const char *format
│       │   0x100000e8a      488d75e0       rsi = [local_20h]
│       │   0x100000e8e      b000           al = 0
│       │   0x100000e90      e841000000     sym.imp.printf ()          ; int printf(const char *format)
│       │   0x100000e95      8945bc         dword [local_44h] = eax
│      ┌──< 0x100000e98      e911000000     goto 0x100000eae
│      ││   ; CODE XREF from 0x100000e02 (entry0)
│      │└─> 0x100000e9d      488d3dfe0000.  rdi = str.See_it_s_impossible ; 0x100000fa2 ; "See it's impossible!\n" ; const char *format
│      │    0x100000ea4      b000           al = 0
│      │    0x100000ea6      e82b000000     sym.imp.printf ()          ; int printf(const char *format)
│      │    0x100000eab      8945b8         dword [local_48h] = eax
│      │    ; CODE XREF from 0x100000e98 (entry0)
│      └──> 0x100000eae      488b054b0100.  rax = qword [reloc.__stack_chk_guard] ; [0x100001000:8]=0
│           0x100000eb5      488b00         rax = qword [rax]
│           0x100000eb8      483b45f8       var = rax - qword [local_8h]
│       ┌─< 0x100000ebc      0f8508000000   if (var) goto 0x100000eca
│       │   0x100000ec2      31c0           eax = 0
│       │   0x100000ec4      4883c450       rsp += 0x50                ; 'P'
│       │   0x100000ec8      5d
│       │   0x100000ec9      c3             return
└       └─> 0x100000eca      e801000000     sym.imp.__stack_chk_fail () ; void __stack_chk_fail(void)
[0x100000dc0]> oo+
[0x100000dc0]> px 10 @ 0x100000dfb+3
- offset -    0 1  2 3  4 5  6 7  8 9  A B  C D  E F  0123456789ABCDEF
0x100000dfe  0289 45d0 0f85 9500 0000                 ..E.......
[0x100000dc0]> wx 01 @ 0x100000dfb+3
[0x100000dc0]> px 10 @ 0x100000dfb+3
- offset -    0 1  2 3  4 5  6 7  8 9  A B  C D  E F  0123456789ABCDEF
0x100000dfe  0189 45d0 0f85 9500 0000                 ..E.......
[0x100000dc0]> q

❯ ./main
welcome to the impossible program!
Congratulation for achieving the impossible!
flag: ctf{first_binary_patch}
```

Flag: `ctf{first_binary_patch}`