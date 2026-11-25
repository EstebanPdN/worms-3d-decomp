/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_threshold_event_8008e144)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80023128 = 0x80023128;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80178C48 = 0x80178c48;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.s8_threshold_event_8008e144 0x8008e144 : { *(.text.s8_threshold_event_8008e144) }
  .sdata 0x804aa7d4 (NOLOAD) : {
    . = 0x0; lbl_804AA7D4 = .;
    . = 0x35b8; lbl_804ADD8C = .;
    . = 0x6f80; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
