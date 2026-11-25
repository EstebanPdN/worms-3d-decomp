/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_disc_stream_read_80218948)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fdcac = 0x801fdcac;
fn_802fa988 = 0x802fa988;
fn_80343994 = 0x80343994;
memcpy = 0x802eee50;
SECTIONS {
  .text.w3d_d30k_disc_stream_read_80218948 0x80218948 : { *(.text.w3d_d30k_disc_stream_read_80218948) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
