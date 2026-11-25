/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_80104128)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_8039959c = 0x8039959c;
lbl_803995ac = 0x803995ac;
SECTIONS {
  .text.s8_bound_80104128 0x80104128 : { *(.text.s8_bound_80104128) }
  .sdata 0x804aaf90 (NOLOAD) : {
    . = 0x0; lbl_804aaf90 = .;
    . = 0x41ec; lbl_804af17c = .;
    . = 0x41f0; lbl_804af180 = .;
    . = 0x41f4; lbl_804af184 = .;
    . = 0x41f8; lbl_804af188 = .;
    . = 0x41fc; lbl_804af18c = .;
    . = 0x4200; lbl_804af190 = .;
    . = 0x4204; lbl_804af194 = .;
    . = 0x4208; lbl_804af198 = .;
    . = 0x420c; lbl_804af19c = .;
    . = 0x4210; lbl_804af1a0 = .;
    . = 0x4218; lbl_804af1a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
