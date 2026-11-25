/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802b0fec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178D1C = 0x80178d1c;
fn_80178D28 = 0x80178d28;
fn_80264658 = 0x80264658;
fn_802AFF50 = 0x802aff50;
fn_802B1CEC = 0x802b1cec;
fn_80342A78 = 0x80342a78;
SECTIONS {
  .text.w3d_auto_802b0fec 0x802b0fec : { *(.text.w3d_auto_802b0fec) }
  .sdata 0x804abb44 (NOLOAD) : {
    . = 0x0; lbl_804ABB44 = .;
    . = 0x124; lbl_804ABC68 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
