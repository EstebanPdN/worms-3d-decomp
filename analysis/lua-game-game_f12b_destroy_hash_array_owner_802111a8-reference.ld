/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._12F12bOwner304)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__dl__12F12bOwner304Pv = 0x801fe1f8;
fn_8020c5c4 = 0x8020c5c4;
fn_80210990 = 0x80210990;
fn_802134fc = 0x802134fc;
fn_80341588 = 0x80341588;
fn_8035c81c = 0x8035c81c;
vt_80419668 = 0x80419668;
vt_80419688 = 0x80419688;
vt_80419700 = 0x80419700;
SECTIONS {
  .text._._12F12bOwner304 0x802111a8 : { *(.text._._12F12bOwner304) }
  .sdata 0x804b18fc (NOLOAD) : {
    . = 0x0; lbl_804b18fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
