/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_dispatch_normal_8001baf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
motion_800ec400 = 0x800ec400;
normal_8043ae38 = 0x8043ae38;
one_8036b070 = 0x8036b070;
position_8041e85c = 0x8041e85c;
select_800bd920 = 0x800bd920;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_cx14a_dispatch_normal_8001baf4 0x8001baf4 : { *(.text.w3d_cx14a_dispatch_normal_8001baf4) }
  .sdata 0x804aa77c (NOLOAD) : {
    . = 0x0; actor_804aa77c = .;
    . = 0x7008; selected_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
