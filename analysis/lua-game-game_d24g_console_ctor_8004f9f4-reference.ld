/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_console_ctor_8004f9f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Text = 0x803426b8;
buf_803f3ff4 = 0x803f3ff4;
s_80377ec0 = 0x80377ec0;
s_80377ecc = 0x80377ecc;
s_80377ed0 = 0x80377ed0;
s_80377edc = 0x80377edc;
s_80377ee0 = 0x80377ee0;
s_80377ef0 = 0x80377ef0;
s_80377ef4 = 0x80377ef4;
s_80377f00 = 0x80377f00;
s_80377f04 = 0x80377f04;
s_80377f0c = 0x80377f0c;
s_80377f10 = 0x80377f10;
s_80377f1c = 0x80377f1c;
s_80377f20 = 0x80377f20;
s_80377f28 = 0x80377f28;
s_80377f2c = 0x80377f2c;
strcpy = 0x802ef2fc;
vt_8040eae0 = 0x8040eae0;
w3d_base_801628b0 = 0x801628b0;
w3d_lines_802cc0ac = 0x802cc0ac;
w3d_list_802109dc = 0x802109dc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d24g_console_ctor_8004f9f4 0x8004f9f4 : { *(.text.w3d_d24g_console_ctor_8004f9f4) }
  .sdata 0x804aaa04 (NOLOAD) : {
    . = 0x0; g_804aaa04 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
