/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_release_actor_record_80347240)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_base_destroy_8015a39c = 0x8015a39c;
cx9c_heap_release_80209920 = 0x80209920;
cx9c_member_destroy_80126230 = 0x80126230;
SECTIONS {
  .text.w3d_cx9c_release_actor_record_80347240 0x80347240 : { *(.text.w3d_cx9c_release_actor_record_80347240) }
  .sdata 0x804b0044 (NOLOAD) : {
    . = 0x0; cx9c_heap_804b0044 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
