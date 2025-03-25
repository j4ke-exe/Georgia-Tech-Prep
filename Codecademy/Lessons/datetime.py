# strptime converts date to 1/15/2018
from datetime import datetime

parsed_date = datetime.strptime('Jan 15, 2018', '%b %d, %Y')
parsed_date.year
# strftime converts date to Jan 15, 2018
date_string = datetime.strftime(datetime.now(), '%b %d, %Y')
date_string