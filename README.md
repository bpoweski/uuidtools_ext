UUIDTools Ext
================================

A faster version of https://github.com/sporkmonger/uuidtools that aims for compatibility.

uuidtools
=================================

```bash

$ rake benchmark
16751.9339812355 version 1 per second.
10612.0728501167 version 3 per second.
10276.3410155298 version 4 per second.
10658.4590113611 version 5 per second.
```

uuidtools_ext
=================================

```bash

$ bundle exec rake benchmark
16134.5758441284 version 1 per second.
22674.4506006888 version 3 per second.
10435.7337015681 version 4 per second.
21516.6662562688 version 5 per second.
```
