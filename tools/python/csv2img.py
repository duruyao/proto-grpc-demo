import os
import sys
import csv
import math
import platform
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker


def read_scv_file(filename):
    """

    :param filename:
    :return: [{'k_1': v_1, 'k_2': v2, ...}, {'k_1': v_1, 'k_2': v2, ...}, {'k_1': v_1, 'k_2': v2, ...}, ...]
    """
    ret_list = []

    with open(filename, mode='rt') as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            ret_list.append(row)

    return ret_list


def print_usage():
    """

    :return:
    """
    print('Usage:\n    %s %s <IN_SCV_FILENAME> [OUT_IMAGE_PATH]' % (sys.executable, str(sys.argv[0])))


def check_arg():
    """

    :return: [filename, path] if success, otherwise [[], []]
    """
    filename = ''
    path = ''

    if len(sys.argv) < 2 or len(sys.argv) > 3:
        print_usage()
        return [[], []]

    if not os.path.isfile(str(sys.argv[1])):
        print('No such file \'%s\'' % str(sys.argv[1]))
        return [[], []]

    filename = os.path.realpath(str(sys.argv[1]))  # get absolute path of 'IN_SCV_FILENAME'

    if 3 == len(sys.argv):  # get absolute path of 'OUT_IMAGE_PATH'
        path = str(sys.argv[2])
    else:
        if 'Windows' == platform.system():
            path = filename + '.out\\'
        else:
            path = filename + '.out/'

    if not os.path.exists(path):
        try:
            os.makedirs(path)
        except OSError as e:
            print('Failed to make \'%s\'' % path)
            return []

    return [filename, path]


def draw_img(x_arr, y_arr, title='', x_label='', y_label='', x_unit='', y_unit='', show_img=False, img_dir=''):
    """

    :param x_arr:
    :param y_arr:
    :param title:
    :param x_label:
    :param y_label:
    :param x_unit:
    :param y_unit:
    :param show_img:
    :param img_dir:
    :return:
    """
    x_ = np.asarray(x_arr)
    y_ = np.asarray(y_arr)

    # set size of image
    plt.figure(figsize=(16, 9))
    # set coordinate
    plt.xlim((1, 20))
    plt.ylim((0, 20))
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    x_step = math.ceil(max(x_arr) / 10)
    y_step = math.ceil(max(y_arr) / 10)
    x_ticks = np.arange(0, max(x_arr) + x_step * 2, x_step)
    y_ticks = np.arange(0, max(y_arr) + y_step * 2, y_step)
    plt.xticks(x_ticks)
    plt.yticks(y_ticks)
    # set grid
    plt.grid(axis='y', linestyle='--')
    plt.grid(axis='x', linestyle='--')
    # draw scatter point
    plt.gca().xaxis.set_major_formatter(mticker.FormatStrFormatter('%s' + str(x_unit)))
    plt.gca().yaxis.set_major_formatter(mticker.FormatStrFormatter('%s' + str(y_unit)))
    plt.scatter(x_, y_, s=10, color='blue', alpha=1.0)
    # set title
    plt.title(title)
    # assemble matrix a_
    a_ = np.vstack([x_, np.ones(len(x_))]).T
    # turn y into a column vector
    y_ = y_[:, np.newaxis]
    # direct least square regression
    alpha = np.linalg.lstsq(a_, y_, rcond=None)[0]
    # draw line
    plt.plot(x_, alpha[0] * x_ + alpha[1],
             color='green', label='y = %f * x + %f' % (float(alpha[0]), float(alpha[1])))
    plt.legend()

    # save image
    if len(img_dir):
        try:
            plt.savefig(img_dir)
            print('Save image to \'%s\'' % img_dir)
        except OSError as e:
            print('Failed to save image to \'%s\'' % img_dir, e)
    if show_img:
        plt.show()


def main():
    """

    :return:
    """
    [csv_filename, img_path] = check_arg()
    if not (len(csv_filename) and len(img_path)):
        exit(1)

    csv_list = read_scv_file(csv_filename)

    key_num = len(list(csv_list[0].keys()))
    key_list = []
    data_list = []

    for idx in range(key_num):
        key_list.append(list(csv_list[0].keys())[idx])
        data_list.append([])

    for d in csv_list:
        for idx in range(key_num):
            data_list[idx].append(int(d[key_list[idx]]))

    # print(data_list)
    draw_img(data_list[1], data_list[3], 'Title 1',
             x_label=str(key_list[1]), y_label=str(key_list[3]),
             x_unit=' B', y_unit=' ms', show_img=False, img_dir=img_path + '1.png')
    draw_img(data_list[2], data_list[4], 'Title 2',
             x_label=str(key_list[2]), y_label=str(key_list[4]),
             x_unit=' B', y_unit=' ms', show_img=False, img_dir=img_path + '2.png')


if __name__ == '__main__':
    main()
