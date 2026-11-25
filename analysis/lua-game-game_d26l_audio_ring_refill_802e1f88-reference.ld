/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_audio_ring_refill_802e1f88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e1f54 = 0x802e1f54;
fn_802fa95c = 0x802fa95c;
fn_802fa988 = 0x802fa988;
fn_802fdb80 = 0x802fdb80;
fn_802fdb94 = 0x802fdb94;
fn_80311254 = 0x80311254;
fn_8031130c = 0x8031130c;
SECTIONS {
  .text.d26l_audio_ring_refill_802e1f88 0x802e1f88 : { *(.text.d26l_audio_ring_refill_802e1f88) }
  .sdata 0x804b190c (NOLOAD) : {
    . = 0x0; mixer_804b190c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
