/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9a_plan_create_append_80016ad0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
object_allocate_8001523c = 0x8001523c;
plan_construct_80015d04 = 0x80015d04;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cx9a_plan_create_append_80016ad0 0x80016ad0 : { *(.text.w3d_cx9a_plan_create_append_80016ad0) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; context_804aa6c0 = .;
    . = 0x40; plans_804aa700 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
