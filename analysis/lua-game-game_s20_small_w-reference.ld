/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_copy_record_80174274)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80177eb0 = 0x80177eb0;
fn_8020bd38 = 0x8020bd38;
SECTIONS {
  .text.w3d_s20_copy_record_80174274 0x80174274 : { *(.text.w3d_s20_copy_record_80174274) }
  .text.w3d_s20_query_slot_80176cd4 0x80176cd4 : { *(.text.w3d_s20_query_slot_80176cd4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
