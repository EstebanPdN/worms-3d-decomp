/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80017cc4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80007D58 = 0x80007d58;
fn_80008098 = 0x80008098;
fn_80008D84 = 0x80008d84;
fn_80009404 = 0x80009404;
fn_8000953C = 0x8000953c;
lbl_8036A838 = 0x8036a838;
lbl_8036A83C = 0x8036a83c;
SECTIONS {
  .text.w3d_auto_80017cc4 0x80017cc4 : { *(.text.w3d_auto_80017cc4) }
  .rodata 0x8036a830 : { *(.rodata) }
  .sdata 0x804aa574 (NOLOAD) : {
    . = 0x0; lbl_804AA574 = .;
    . = 0x18; lbl_804AA58C = .;
    . = 0x2c; lbl_804AA5A0 = .;
    . = 0x164; lbl_804AA6D8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
