# Bit Manipulation Library

This is part of my self studies, at the time of writing, I am working on bits and binary. I decided to create a bit manipulation library as part of my studies into comp sci.

## Documentation

#### Basic per bit manipulation
```bit_is_set``` Checks if the bit at the index via the argument _bit_position_ is set, returns a bool.

```bit_set``` Sets the bit at the index via the argument _bit_position_.

```bit_unset``` Unsets the bit at the index via the argument _bit_position_. 

```bit_toggle``` Sets the bit at the index via the argument _bit_position_ to its oppposite value, toggling the bit.

#### Counting and searching, returns 99 if not found, arbitrary retun value

```toggled_bit_count``` Returns the nuumber of toggled bits in value

```first_toggled_bit``` Returns the index of the position of the first toggled bit (zero based index)

```last_toggled_bit``` Returns the index of the position of the last toggled bit (zero based index)

#### Range bit manipulation

```extract_range``` Extracts the bits in the range starting at bit _start_ (inclusive) for _num_bits_ and returns it as a string.  

```insert_bits``` Inserts bits of _src_ at position _start_ into _value_, inserts the number of bits _num_bits_.

#### Printing

```binary_to_string```Returns the given varible as binary in a string.

```print_binary``` Prints the binary.

```pretty_print_binary``` Prints the binary in a pretty manner :3
