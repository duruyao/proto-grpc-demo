import os
import sys
import csv
import platform


def read_scv_file(filename):
    """

    :param filename:
    :return:
    """
    scv_list_ = []

    with open(filename, mode='rt') as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            scv_list_.append(row)

    return scv_list_


def print_usage():
    """

    :return:
    """
    print('Usage:\n    %s %s <IN_SCV_FILENAME> [OUT_IMAGE_PATH]' % (sys.executable, str(sys.argv[0])))


def check_arg():
    """

    :return:
    """
    csv_filename_ = ''
    img_path_ = ''

    if len(sys.argv) < 2 or len(sys.argv) > 3:
        print_usage()
        return []

    if not os.path.isfile(str(sys.argv[1])):
        print('[ERROR] no such file \'%s\'' % str(sys.argv[1]))
        return []

    csv_filename_ = os.path.realpath(str(sys.argv[1]))  # get absolute path of 'IN_SCV_FILENAME'

    if 3 == len(sys.argv):  # get absolute path of 'OUT_IMAGE_PATH'
        img_path_ = str(sys.argv[2])
    else:
        img_path_ = csv_filename_ + '.out'

    if not os.path.exists(img_path_):
        try:
            os.makedirs(img_path_)
        except OSError as e:
            print('[ERROR] failed to make \'%s\'' % img_path_)
            return []

    return [csv_filename_, img_path_]


def main():
    """

    :return:
    """
    csv_filename = ''
    img_path = ''

    try:
        [csv_filename, img_path] = check_arg()
    except ValueError as e:
        exit(1)

    csv_list = read_scv_file(csv_filename)
    print(csv_list)


if __name__ == '__main__':
    main()
