/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_register_fields_800dae1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c1620 = 0x800c1620;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_80162024 = 0x80162024;
fn_8016239c = 0x8016239c;
SECTIONS {
  .text.s8_register_fields_800dae1c 0x800dae1c : { *(.text.s8_register_fields_800dae1c) }
  .sdata 0x804aebc4 (NOLOAD) : {
    . = 0x0; lbl_804aebc4 = .;
    . = 0x8; lbl_804aebcc = .;
    . = 0x10; lbl_804aebd4 = .;
    . = 0x18; lbl_804aebdc = .;
    . = 0x20; lbl_804aebe4 = .;
    . = 0x28; lbl_804aebec = .;
    . = 0x30; lbl_804aebf4 = .;
    . = 0x38; lbl_804aebfc = .;
    . = 0x40; lbl_804aec04 = .;
    . = 0x48; lbl_804aec0c = .;
    . = 0x2b90; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
