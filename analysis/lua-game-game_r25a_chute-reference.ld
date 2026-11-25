/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r25a_initialize_chute_message_800da3fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__21SharedString_8020bb54PCc = 0x8020bb54;
fn_801190b4 = 0x801190b4;
fn_8015adf4 = 0x8015adf4;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
lbl_8038975c = 0x8038975c;
SECTIONS {
  .text.w3d_r25a_initialize_chute_message_800da3fc 0x800da3fc : { *(.text.w3d_r25a_initialize_chute_message_800da3fc) }
  .sdata 0x804aeb8c (NOLOAD) : {
    . = 0x0; lbl_804aeb8c = .;
    . = 0x2bc8; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
