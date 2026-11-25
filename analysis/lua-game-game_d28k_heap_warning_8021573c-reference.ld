/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_heap_warning_8021573c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802156c8 = 0x802156c8;
fn_802156f8 = 0x802156f8;
lbl_803b36cc = 0x803b36cc;
lbl_803b36d8 = 0x803b36d8;
lbl_803b36e4 = 0x803b36e4;
lbl_803b36f4 = 0x803b36f4;
lbl_803b3704 = 0x803b3704;
lbl_803b370c = 0x803b370c;
lbl_803b3714 = 0x803b3714;
lbl_803b371c = 0x803b371c;
lbl_803b3730 = 0x803b3730;
lbl_803b3744 = 0x803b3744;
lbl_803b3758 = 0x803b3758;
lbl_803b3768 = 0x803b3768;
lbl_803b3770 = 0x803b3770;
lbl_803b3780 = 0x803b3780;
lbl_803b378c = 0x803b378c;
lbl_803b379c = 0x803b379c;
lbl_803b37ac = 0x803b37ac;
lbl_803b37b8 = 0x803b37b8;
lbl_803b37c8 = 0x803b37c8;
lbl_80400768 = 0x80400768;
strlen = 0x802ef9c0;
SECTIONS {
  .text.w3d_d28k_heap_warning_8021573c 0x8021573c : { *(.text.w3d_d28k_heap_warning_8021573c) }
  .sdata 0x804aba80 (NOLOAD) : {
    . = 0x0; lbl_804aba80 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
