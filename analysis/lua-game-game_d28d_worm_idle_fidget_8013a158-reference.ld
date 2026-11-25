/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_idle_fidget_8013a158)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
control_801817e0 = 0x801817e0;
free_801981f8 = 0x801981f8;
play_801359ec = 0x801359ec;
query_800fc6dc = 0x800fc6dc;
rand_80162c20 = 0x80162c20;
registry_80343810 = 0x80343810;
reset_8013c54c = 0x8013c54c;
speak_8013bd0c = 0x8013bd0c;
SECTIONS {
  .text.d28d_worm_idle_fidget_8013a158 0x8013a158 : { *(.text.d28d_worm_idle_fidget_8013a158) }
  .rodata 0x8039f6f4 : { *(.rodata) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; n_804ab100 = .;
    . = 0x6c; n_804ab16c = .;
    . = 0xec; n_804ab1ec = .;
    . = 0xf0; n_804ab1f0 = .;
    . = 0xf4; n_804ab1f4 = .;
    . = 0xf8; n_804ab1f8 = .;
    . = 0xfc; n_804ab1fc = .;
    . = 0x100; n_804ab200 = .;
    . = 0x104; n_804ab204 = .;
    . = 0x108; n_804ab208 = .;
    . = 0x10c; n_804ab20c = .;
    . = 0x120; n_804ab220 = .;
    . = 0x124; n_804ab224 = .;
    . = 0x128; n_804ab228 = .;
    . = 0x12c; n_804ab22c = .;
    . = 0x130; n_804ab230 = .;
    . = 0x134; n_804ab234 = .;
    . = 0x138; n_804ab238 = .;
    . = 0x13c; n_804ab23c = .;
    . = 0x140; n_804ab240 = .;
    . = 0x144; n_804ab244 = .;
    . = 0x148; n_804ab248 = .;
    . = 0x14c; n_804ab24c = .;
    . = 0x46e4; n_804af7e4 = .;
    . = 0x46e8; n_804af7e8 = .;
    . = 0x46ec; n_804af7ec = .;
    . = 0x6688; system_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
