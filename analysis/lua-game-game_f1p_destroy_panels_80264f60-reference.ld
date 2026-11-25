/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._13F1pPanelOwner)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._21F1pPanelBase_8015ff2c = 0x8015ff2c;
_._23F1pPanelMember_802afc40 = 0x802afc40;
vt_8041bc00 = 0x8041bc00;
vt_8041bc50 = 0x8041bc50;
SECTIONS {
  .text._._13F1pPanelOwner 0x80264f60 : { *(.text._._13F1pPanelOwner) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
