import React, { Component } from 'react';
import PropTypes from 'prop-types';

class DateForm extends Component {
    constructor(props) {
        super(props);
        this.state = {
            date: this.props.selectedDate,
        };
    }

    handleDateChange = (event) => {
        const newDate = event.target.value;
        this.setState({ date: newDate });
        this.props.onDateChange(newDate);
    };

    render() {
        return (
            <div>
                <input
                    type="text"
                    value={this.state.date}
                    onChange={this.handleDateChange}
                    className="form-control col-2"
                />
                <h1>Articles published on {this.state.date}</h1>
            </div>
        );
    }
}

DateForm.propTypes = {
    selectedDate: PropTypes.string.isRequired,
    onDateChange: PropTypes.func.isRequired,
};

export default DateForm;
