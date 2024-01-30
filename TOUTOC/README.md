# TOUTOC

Create the Target File:
``
  touch example.txt
``

Compile the Vulnerable Code:
``
  gcc vulnerable.c -o vulnerable
``


Run the Vulnerable Code:
``
  ./vulnerable
``

Modify the File Content:

While the vulnerable code is running (after the Time-of-Check but before the Time-of-Use), you can open another terminal window or a separate terminal tab to manually modify the file content. Run the following command to modify the file


``
  echo "Malicious content" > example.txt
``

The file content is now modified with the "Malicious content" string.
