# tinydex
Simple command line utility for indexing text records

Primary Goals:

    * Simplicity: Input and output format should be text records

    * Small: Minimal use of computational resources

    * Flexible: Adopt a modular framework and integrate well with
    existing nix tools.


Target Work Environments:

    * Datasets between 50 and 10,000 records

    * Records between 10 and 100 characters

    * BSD and Linux systems


Use Cases:

    * Grouping lists of items by common text

    * Creating a lookup index for simple searches

    * Measure the relative frequencies of common text strings

    * Find the amount of co-incidence of index text

    * Rank records on low co-incidence indices (eg sentiment analysis)


Input format:

    * Newline-delimitted records

    * Records starting with @ treat the record as a filename,
    and imports the contents of the file as a single record

    * Records starting with & treat the record as a filename,
    and imports the contents of the file as a list of records

    * Records starting with ! treat the record as a shell script snippet,
    and are evaluated as a single record

    * Records starting with $ treat the record as a shell script snippet,
    and are evaluated as a list of records

    * Specially interpretted records above need to be explicitly set with
    corresponding flags to work. So for @records to import files, -@
    needs to be passed. Otherwise @file will be treated as a literal string
