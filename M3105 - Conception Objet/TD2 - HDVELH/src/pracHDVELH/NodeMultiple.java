package pracHDVELH;

public class NodeMultiple {
    public static final int ERROR_SObjectAObjectUS_INDEX_OUT_OF_RANGE = -1;
    public static final String ERROR_MSG_INDEX_OUT_OF_RANGE = "Index out of range";
    public static final int NODE_MAX_ARITY = 10;
    private Object data;
    private NodeMultiple[] daughters;

    public NodeMultiple() {}

    public NodeMultiple(Object data) {
        this.data = data;
        this.daughters = new NodeMultiple[NODE_MAX_ARITY];
    }

    @Override
    public String toString() {
        return this.data.toString();
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public NodeMultiple[] getDaughters() {
        return daughters;
    }

    public void setDaughters(NodeMultiple[] daughters) {
        this.daughters = daughters;
    }

    public NodeMultiple getDaughter(int i) throws Exception {
        if (i >= 10 || i < 0) throw new Exception(ERROR_MSG_INDEX_OUT_OF_RANGE);
        return this.daughters[i];
    }

    public void setDaughter(NodeMultiple daughter, int i) {
    	this.daughters[i] = daughter;
    }

    public void addDaughter(NodeMultiple daughter) {
        for (int i = 0; i < NODE_MAX_ARITY - 1; ++i) {
            if (daughters[i] == null) {
            	daughters[i] = daughter;
                return;
            }
        }
    }

    public boolean hasDaughter() {
        for (int i = 0; i < NODE_MAX_ARITY - 1; ++i) {
            if (daughters[i] != null) {
                return true;
            }
        }
        return false;
    }
}