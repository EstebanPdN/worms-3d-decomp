/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40e_stream_fill_next_801e47e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e4a4c = 0x801e4a4c;
fn_802f5568 = 0x802f5568;
fn_803238fc = 0x803238fc;
memset = 0x802eefe0;
w3d_stream_slot_finish_801e4794 = 0x801e4794;
SECTIONS {
  .text.w3d_d40e_stream_fill_next_801e47e8 0x801e47e8 : { *(.text.w3d_d40e_stream_fill_next_801e47e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
