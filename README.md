# Google Mock Issues
Experiments with Google Mock


# Are you seeing errors in your Google Mock build that resemble 


```bash
*** Error in `./sample': free(): invalid pointer: 0x09efd28c ***
```

```bash
*** Error in double free or corruption (!prev): ***
```


# These errors are related to including -lgtest followed by -lgmock

You can verify this with this sample code


```bash
make correct
sample
```

vs

```bash
make incorrect
sample
```

# Further notes on this are at https://github.com/jlangr/c2/issues/3