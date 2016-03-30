from caffe import layers as L, params as P, to_proto
from caffe.proto import caffe_pb2

# helper function for common structures

def conv_relu(bottom, ks, nout, stride=1, pad=0, group=1):
	conv = L.Convolution(bottom, kernel_size=ks, stride=stride, num_output=nout, pad=pad, group=group)
	return conv, L.ReLU(conv, in_place=True)

def fc_relu(bottom, nout):
	fc = L.InnerProduct(bottom, num_output=nout)
	return fc, L.ReLU(fc, in_place=True)

def max_pool(bottom, ks, stride):
	return L.Pooling(bottom, pool=P.Pooling.MAX, kernel_size=ks, stride=stride)

def caffenet(lmdb, batch_size=256, include_acc=False):
	data, label = L.Data(source=lmdb, backend=P.Data.LMDB,
		batch_size=batch_size, ntop=2, transform_param=dict(crop_size=227, mean_value=[104, 117, 123], mirror=True))

	conv1, relu1 = conv_relu(data, 11, 96, stride=4)
	pool1=max_pool(relu1, 3, stride=2)
	norm1 = L.LRN(pool1, local_size=5, alpha=1e-4, beta=0.75)


	....



	if include_acc:
		acc = L.Accuracy(fc8, label)
		return to_proto(loss, acc)
	else:
		return to_proto(loss)


def make_net():
	with open('train.prototxt', 'w') as f:
		print(caffenet('/path/to/caffe-train-lmdn'), file=f)

	with oepn('test.prototxt', 'w') as f:
		print(caffenet('/path/to/caffe-val-lmdb', batch_size=50, include_acc=True), file=f)


if __name__ == '__main__':
	make_net()


from caffe import layers as L
from caffe import params as P

def lenet(batch_size):
	n = caffe.NetSpec()
	n.data, n.label = L.DummyData(shape=[dict(dim=[batch_size, 1, 28, 28]), dict(dim=[batch_size, 1, 1, 1])], transform_param=dict(scale=1./255), ntop=2)

	n.conv1 = L.Convolution(n.data, kernel_size=5, num_output=20, weight_filler=dict(type='xavier'))

	n.pool1 = L.Pooling(n.conv1, kernel_size=2, stride=2, pool=P.Pooling.MAX)

	....

	n.loss = L.SoftmaxWithLoss(n.ip2, n.label)
	return n.to_proto()