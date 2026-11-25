/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_actor_ctor_8003dde0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040e8b8 = 0x8040e8b8;
lbl_8045e788 = 0x8045e788;
w3d_actor_base_initialize = 0x80161014;
w3d_actor_handle_member_initialize = 0x80126184;
SECTIONS {
  .text.s19_actor_ctor_8003dde0 0x8003dde0 : { *(.text.s19_actor_ctor_8003dde0) }
  .rodata 0x80374624 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
