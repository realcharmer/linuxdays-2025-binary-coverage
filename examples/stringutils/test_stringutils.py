import subprocess

def run_program(args):
    result = subprocess.run(
        ["./stringutils"] + args,
        capture_output=True,
        text=True,
        check=True
    )
    return result.stdout.strip()

def test_reverse():
    output = run_program(["reverse", "hello"])
    assert output == "olleh"

def test_palindrome_yes():
    output = run_program(["palindrome", "level"])
    assert output == "Yes"

def test_palindrome_no():
    output = run_program(["palindrome", "world"])
    assert output == "No"
