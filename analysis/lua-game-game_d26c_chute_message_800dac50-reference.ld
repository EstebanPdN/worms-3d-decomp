/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_chute_message_800dac50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
fields_800dae1c = 0x800dae1c;
finish_8015fd1c = 0x8015fd1c;
id_equals_8015f65c = 0x8015f65c;
off_800daffc = 0x800daffc;
start_800db014 = 0x800db014;
stop_800dafa4 = 0x800dafa4;
value_800a830c = 0x800a830c;
SECTIONS {
  .text.d26c_chute_message_800dac50 0x800dac50 : { *(.text.d26c_chute_message_800dac50) }
  .sdata 0x804aebc4 (NOLOAD) : {
    . = 0x0; id_804aebc4 = .;
    . = 0x8; id_804aebcc = .;
    . = 0x10; id_804aebd4 = .;
    . = 0x18; id_804aebdc = .;
    . = 0x20; id_804aebe4 = .;
    . = 0x28; id_804aebec = .;
    . = 0x30; id_804aebf4 = .;
    . = 0x40; id_804aec04 = .;
    . = 0x48; id_804aec0c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
