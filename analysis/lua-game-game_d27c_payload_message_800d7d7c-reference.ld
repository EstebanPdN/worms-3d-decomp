/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_payload_message_800d7d7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
attract_800ecbac = 0x800ecbac;
base_800ea62c = 0x800ea62c;
ctx_80165254 = 0x80165254;
hit_800d84cc = 0x800d84cc;
impulse_800d9c74 = 0x800d9c74;
keyMax_803891ec = 0x803891ec;
keyMin_8038920c = 0x8038920c;
rand_80162bc8 = 0x80162bc8;
read_800fc270 = 0x800fc270;
rest_800d8300 = 0x800d8300;
same_8015f65c = 0x8015f65c;
start_800d80c8 = 0x800d80c8;
stop_800d82cc = 0x800d82cc;
SECTIONS {
  .text.d27c_payload_message_800d7d7c 0x800d7d7c : { *(.text.d27c_payload_message_800d7d7c) }
  .rodata 0x8038922c : { *(.rodata) }
  .sdata 0x804aeaf8 (NOLOAD) : {
    . = 0x0; id_804aeaf8 = .;
    . = 0x8; id_804aeb00 = .;
    . = 0x10; id_804aeb08 = .;
    . = 0x18; id_804aeb10 = .;
    . = 0x20; id_804aeb18 = .;
    . = 0x28; id_804aeb20 = .;
    . = 0x40; id_804aeb38 = .;
    . = 0x48; id_804aeb40 = .;
    . = 0x60; id_804aeb58 = .;
    . = 0x78; id_804aeb70 = .;
    . = 0x80; id_804aeb78 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
