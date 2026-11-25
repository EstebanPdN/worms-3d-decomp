/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800a01c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A064C = 0x800a064c;
fn_800A08AC = 0x800a08ac;
fn_800A12C0 = 0x800a12c0;
fn_800A1608 = 0x800a1608;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_80165254 = 0x80165254;
SECTIONS {
  .text.w3d_auto_800a01c4 0x800a01c4 : { *(.text.w3d_auto_800a01c4) }
  .sdata 0x804ae12c (NOLOAD) : {
    . = 0x0; lbl_804AE12C = .;
    . = 0x8; lbl_804AE134 = .;
    . = 0x10; lbl_804AE13C = .;
    . = 0x18; lbl_804AE144 = .;
    . = 0x20; lbl_804AE14C = .;
    . = 0x28; lbl_804AE154 = .;
    . = 0x30; lbl_804AE15C = .;
    . = 0x38; lbl_804AE164 = .;
    . = 0x40; lbl_804AE16C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
