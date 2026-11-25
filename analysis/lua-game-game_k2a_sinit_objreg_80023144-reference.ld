/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_sinit_objreg_80023144)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80022b18 = 0x80022b18;
FUN_802097ec = 0x802097ec;
__16W3dType_801629f8PvN21ii = 0x801629f8;
w3d_cached_message_name_init = 0x8015f518;
w3d_state_804200a4 = 0x804200a4;
w3d_str_803618f0 = 0x803618f0;
w3d_str_8036c550 = 0x8036c550;
w3d_str_8036c560 = 0x8036c560;
w3d_str_803e7714 = 0x803e7714;
w3d_type_8035faf0 = 0x8035faf0;
SECTIONS {
  .text.k2a_sinit_objreg_80023144 0x80023144 : { *(.text.k2a_sinit_objreg_80023144) }
  .sdata 0x804aca40 (NOLOAD) : {
    . = 0x0; w3d_arena_804aca40 = .;
    . = 0x8; w3d_state_804aca48 = .;
    . = 0xc; w3d_message_804aca4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
