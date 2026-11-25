/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._12F16bOwner296)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._17F16bBase_801799d4 = 0x801799d4;
fn_8020c5c4 = 0x8020c5c4;
fn_80210abc = 0x80210abc;
fn_802134fc = 0x802134fc;
fn_80341588 = 0x80341588;
vt_80412f50 = 0x80412f50;
SECTIONS {
  .text._._12F16bOwner296 0x8018bddc : { *(.text._._12F16bOwner296) }
  .sdata 0x804ab6ac (NOLOAD) : {
    . = 0x0; lbl_804ab6ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
