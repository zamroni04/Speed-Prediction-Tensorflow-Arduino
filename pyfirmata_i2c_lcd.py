from pyfirmata import Arduino, util, STRING_DATA

board = Arduino('COM6')
print("Communication Successfully started")

def msg( text ):
    if text:
        board.send_sysex( STRING_DATA, util.str_to_two_byte_iter( text ) )

msg("Great Python")