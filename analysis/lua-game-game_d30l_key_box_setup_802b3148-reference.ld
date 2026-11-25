/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30l_key_box_setup_802b3148)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_8015adf4 = 0x8015adf4;
fn_8015ae3c = 0x8015ae3c;
fn_80171ee0 = 0x80171ee0;
fn_80171f90 = 0x80171f90;
fn_80171fa0 = 0x80171fa0;
fn_80171ff8 = 0x80171ff8;
fn_80173df0 = 0x80173df0;
fn_80173f88 = 0x80173f88;
fn_80178f54 = 0x80178f54;
fn_801fe1d8 = 0x801fe1d8;
fn_8020c5c4 = 0x8020c5c4;
fn_802ae4d8 = 0x802ae4d8;
fn_802ae5f8 = 0x802ae5f8;
fn_802af220 = 0x802af220;
fn_802af254 = 0x802af254;
fn_80341588 = 0x80341588;
fn_8034357c = 0x8034357c;
fn_80343808 = 0x80343808;
memset = 0x802eefe0;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d30l_key_box_setup_802b3148 0x802b3148 : { *(.text.d30l_key_box_setup_802b3148) }
  .rodata 0x803d7cb4 : { *(.rodata) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; base_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
