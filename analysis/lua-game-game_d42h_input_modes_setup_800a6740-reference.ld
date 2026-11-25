/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42h_input_modes_setup_800a6740)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Mode = 0x800a5d6c;
__builtin_new = 0x801fe1d8;
aim_80054434 = 0x80054434;
attach_8015fb6c = 0x8015fb6c;
cached_8015f5a0 = 0x8015f5a0;
camera_80056178 = 0x80056178;
copy_802ef2fc = 0x802ef2fc;
crate_8005e35c = 0x8005e35c;
fire_80058804 = 0x80058804;
fireu_8005dec0 = 0x8005dec0;
fly_8005c35c = 0x8005c35c;
girder_80059ce4 = 0x80059ce4;
heap_802098d8 = 0x802098d8;
menu_800524d4 = 0x800524d4;
move_80058a68 = 0x80058a68;
quit_8005fbc0 = 0x8005fbc0;
rope_80058f18 = 0x80058f18;
spect_8005e4a4 = 0x8005e4a4;
subscribe_80162024 = 0x80162024;
view_8005da24 = 0x8005da24;
worm_80054d24 = 0x80054d24;
SECTIONS {
  .text.d42h_input_modes_setup_800a6740 0x800a6740 : { *(.text.d42h_input_modes_setup_800a6740) }
  .rodata 0x803812b8 : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; heap_804ae280 = .;
    . = 0x50; m_804ae2d0 = .;
    . = 0x58; m_804ae2d8 = .;
    . = 0x68; m_804ae2e8 = .;
    . = 0x70; m_804ae2f0 = .;
    . = 0x3570; service_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
