/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8028f338)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F5A0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_8029556C = 0x8029556c;
fn_80296498 = 0x80296498;
fn_80296598 = 0x80296598;
SECTIONS {
  .text.w3d_auto_8028f338 0x8028f338 : { *(.text.w3d_auto_8028f338) }
  .text.w3d_auto_8028f4a0 0x8028f4a0 : { *(.text.w3d_auto_8028f4a0) }
  .text.w3d_auto_802950c8 0x802950c8 : { *(.text.w3d_auto_802950c8) }
  .text.w3d_auto_8029550c 0x8029550c : { *(.text.w3d_auto_8029550c) }
  .sdata 0x804abbfc (NOLOAD) : {
    . = 0x0; lbl_804ABBFC = .;
    . = 0x5100; lbl_804B0CFC = .;
    . = 0x5108; lbl_804B0D04 = .;
    . = 0x5110; lbl_804B0D0C = .;
    . = 0x5118; lbl_804B0D14 = .;
    . = 0x5120; lbl_804B0D1C = .;
    . = 0x5128; lbl_804B0D24 = .;
    . = 0x5130; lbl_804B0D2C = .;
    . = 0x5138; lbl_804B0D34 = .;
    . = 0x5140; lbl_804B0D3C = .;
    . = 0x5148; lbl_804B0D44 = .;
    . = 0x5160; lbl_804B0D5C = .;
    . = 0x5168; lbl_804B0D64 = .;
    . = 0x5170; lbl_804B0D6C = .;
    . = 0x5178; lbl_804B0D74 = .;
    . = 0x5180; lbl_804B0D7C = .;
    . = 0x5188; lbl_804B0D84 = .;
    . = 0x5190; lbl_804B0D8C = .;
    . = 0x5198; lbl_804B0D94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
