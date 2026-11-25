/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002ae70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800C53A0 = 0x800c53a0;
fn_800FCEA0 = 0x800fcea0;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80165254 = 0x80165254;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_8002ae70 0x8002ae70 : { *(.text.w3d_auto_8002ae70) }
  .sdata 0x804acc34 (NOLOAD) : {
    . = 0x0; lbl_804ACC34 = .;
    . = 0x10; lbl_804ACC44 = .;
    . = 0x28; lbl_804ACC5C = .;
    . = 0x4b20; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
